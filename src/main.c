/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:17:16 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/11 18:21:56 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	final_check(t_file file)
{
	t_list	*head;
	char	**mat;
	char	*line;

	head = file.lines;
	while (head)
	{
		line = (char *)head->content;
		mat = ft_split(line, 32);
		if (line[0] != 'F' && line[0] != 'C'
			&& identify_direction(mat[0], NULL) == false && !is_map_line(line)
			&& !is_only_whitespace(line))
		{
			free_mat(mat);
			return (error_msg("Invalid line in the file"), false);
		}
		free_mat(mat);
		head = head->next;
	}
	return (true);
}

int game_loop(t_cub *cub)
{
    move_player(cub);
    mlx_clear_window(cub->mlx, cub->win);
    update_door(cub);
    render_frame(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    return (0);
}

int     close_game(t_cub *cub)
{
    int i;
    
    i = 0;
    while (i < 5)
    {
        if (cub->door[i]->img)
            mlx_destroy_image(cub->mlx, cub->door[i]->img);
        free(cub->door[i]);
        i++;
    }
    free(cub->cub3d->texture.door[0]);
    free(cub->cub3d->texture.door[1]);
    free(cub->cub3d->texture.door[2]);
    free(cub->cub3d->texture.door[3]);
    free(cub->cub3d->texture.door[4]);
    free(cub->cub3d->texture.weap);
    mlx_destroy_image(cub->mlx, cub->weap->img);
    mlx_destroy_image(cub->mlx, cub->north->img);
    mlx_destroy_image(cub->mlx, cub->south->img);
    mlx_destroy_image(cub->mlx, cub->east->img);
    mlx_destroy_image(cub->mlx, cub->west->img);
    free_structs(cub->cub3d);
    if (cub && cub->mlx && cub->img)
	    mlx_destroy_image(cub->mlx, cub->img);
    if (cub && cub->mlx && cub->win)
	    mlx_destroy_window(cub->mlx, cub->win);
    if (cub && cub->mlx)
	    mlx_destroy_display(cub->mlx);
    free(cub->mlx);
    exit(1);
    return (0);
}

int main(int ac, char **av)
{
    t_cub   cub;
    t_player player;
    t_cub3d	cub3d;
    t_text north;
    t_text south;
    t_text east;
    t_text west;
    t_text weap;
    
    cub.north = &north;
    cub.south = &south;
    cub.east = &east;
    cub.west = &west;
    cub.weap = &weap;

    cub.cub3d = &cub3d;
    if (ac != 2)
		return (error_msg("Usage: ./cub3d map.ber\n"), 1);
    if (validate_extension((av[1]), ".cub") == false)
		return (error_msg("Invalid file extension. Expected .cub\n"), 1);
	ft_memset(cub.cub3d, 0, sizeof(t_cub3d));
	if (check_file(av[1], &cub.cub3d->file) == false)
		return (ft_lstclear(&cub.cub3d->file.lines, free), 1);
	if (check_texture(&cub.cub3d->file, &cub.cub3d->texture) == false)
		return (free_structs(cub.cub3d), 1);
	if (check_color(&cub.cub3d->file, &cub.cub3d->color) == false)
		return (free_structs(cub.cub3d), 1);
	if (check_map(&cub.cub3d->file, &cub.cub3d->map) == false)
		return (free_structs(cub.cub3d), 1);
    player.map = cub.cub3d->map.grid;
    player.map_height = cub.cub3d->map.height;
    player.map_width = cub.cub3d->map.width;
	if (final_check(cub.cub3d->file) == false)
		return (free_structs(cub.cub3d), 1);
    cub.player = &player;
    cub.color = &cub.cub3d->color;
    cub.player->weapon_timer = 0;
    initialize_player(&player);
    cub.player->move_down = 0;
    cub.player->move_up = 0;
    cub.player->move_left = 0;
    cub.player->move_right = 0;
    cub.player->rot_left = 0;
    cub.player->rot_right = 0;
    cub.player->is_moving = 0;
    cub.key_close = 0;
    cub.mlx = mlx_init();
    if (!cub.mlx)
    {
        free_structs(cub.cub3d);
        close_game(&cub);
    }
    init_textures(&cub, &cub.cub3d->texture);
    cub.win = mlx_new_window(cub.mlx,  WIDTH, HEIGHT, "cub3d");
    cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
    cub.addr = mlx_get_data_addr(cub.img, &cub.bpp, &cub.size_line, &cub.endian);
    mlx_loop_hook(cub.mlx, game_loop, &cub);
    mlx_hook(cub.win, 17, 0, close_game, &cub);
    mlx_hook(cub.win, 03, (1L << 1), key_release, &cub);
    mlx_hook(cub.win, 02, (1L << 0), key_press, &cub);
    mlx_hook(cub.win, 06, (1L << 06), mouse_move, &cub);
    mlx_loop(cub.mlx);
    return (0);
}
