/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:03:52 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/22 11:23:37 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		if (line[0] != 'F' && line[0] != 'C' && identify_direction(mat[0],
				NULL) == false && !is_map_line(line, "01NSEWD ")
			&& !is_only_whitespace(line))
		{
			free_mat(mat);
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Invalid line in the file: ", 2);
			ft_putendl_fd(line, 2);
			return (false);
		}
		free_mat(mat);
		head = head->next;
	}
	return (true);
}

void	ft_game(t_cub_bonus *cub)
{
	if (!cub->mlx)
	{
		free_structs(cub->cub3d);
		exit (1);
	}
	init_textures(cub, &cub->cub3d->texture);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line,
			&cub->endian);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_hook(cub->win, 17, 0, close_game, cub);
	mlx_hook(cub->win, 03, (1L << 1), key_release, cub);
	mlx_hook(cub->win, 02, (1L << 0), key_press, cub);
	mlx_hook(cub->win, 06, (1L << 06), mouse_move, cub);
	mlx_loop(cub->mlx);
}

int	ft_parse(t_cub_bonus *cub, t_player *player, char *av[])
{
	if (validate_extension((av[1]), ".cub") == false)
		return (error_msg("Invalid file extension. Expected .cub\n"), 1);
	ft_memset(cub->cub3d, 0, sizeof(t_cub3d));
	if (check_file(av[1], &cub->cub3d->file) == false)
		return (ft_lstclear(&cub->cub3d->file.lines, free), 1);
	if (check_texture(&cub->cub3d->file, &cub->cub3d->texture) == false)
		return (free_structs(cub->cub3d), 1);
	if (check_color(&cub->cub3d->file, &cub->cub3d->color) == false)
		return (free_structs(cub->cub3d), 1);
	if (check_map_bonus(&cub->cub3d->file, &cub->cub3d->map) == false)
		return (free_structs(cub->cub3d), 1);
	player->map = cub->cub3d->map.grid;
	player->map_height = cub->cub3d->map.height;
	player->map_width = cub->cub3d->map.width;
	if (final_check(cub->cub3d->file) == false)
		return (free_structs(cub->cub3d), 1);
	cub->player = player;
	cub->color = &cub->cub3d->color;
	cub->player->weapon_timer = 0;
	cub->key_close = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_cub_bonus	cub;
	t_render	render;
	t_player	player;
	t_cub3d		cub3d;
	t_text		texture[5];

	cub.north = &texture[0];
	cub.south = &texture[1];
	cub.east = &texture[2];
	cub.west = &texture[3];
	cub.weap = &texture[4];
	cub.render = &render;
	cub.cub3d = &cub3d;
	if (ac != 2)
		return (error_msg("Usage: ./cub3d map.cub\n"), 1);
	if (ft_parse(&cub, &player, av))
		return (1);
	initialize_player(&player);
	cub.mlx = mlx_init();
	ft_game(&cub);
	return (0);
}
