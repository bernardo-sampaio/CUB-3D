/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:17:16 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/04 17:42:56 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int game_loop(t_cub *cub)
{
    move_player(cub);
    mlx_clear_window(cub->mlx, cub->win);
    render_frame(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    return (0);
}

int     close_game(t_cub *cub)
{
    mlx_destroy_image(cub->mlx, cub->img);
    mlx_destroy_window(cub->mlx, cub->win);
    mlx_destroy_display(cub->mlx);
    int i = 0;
    while (cub->player->map[i])
    {
        free(cub->player->map[i]);
        i++;
    }
    free(cub->player->map);
    exit(1);
    return (0);
}

int main(int ac, char **av)
{
    t_cub   cub;
    t_player player;
    t_text north;
    t_text south;
    t_text east;
    t_text weast;   
    
    cub.north = &north;
    cub.south = &south;
    cub.east = &east;
    cub.weast = &weast;
    if (ac != 2)
        return (1);
    cub.player = &player;
    player.map = ft_get_map(&player, av[1]);
    initialize_player(&player);
    cub.player->move_down = 0;
    cub.player->move_up = 0;
    cub.player->move_left = 0;
    cub.player->move_right = 0;
    cub.player->rot_left = 0;
    cub.player->rot_right = 0;
    cub.key_close = 0;
    cub.mlx = mlx_init();
    if (!cub.mlx)
        close_game(&cub);
    init_textures(&cub);
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
