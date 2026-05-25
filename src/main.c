/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:17:16 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 19:27:51 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int game_loop(t_cub *cub)
{
    move_player(cub->player);
    render_frame(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    return (0);
}
int main(int ac, char **av)
{
    t_cub   cub;
    t_player player;

    if (ac != 2)
        return (1);
    cub.player = &player;
    player.map = ft_get_map(&player, av[1]);
    initialize_player(&player);
    cub.player->move_down = 0;
    cub.player->move_up = 0;
    cub.player->move_left = 0;
    cub.player->move_right = 0;
    cub.mlx = mlx_init();
    cub.win = mlx_new_window(cub.mlx,  WIDTH, HEIGHT, "cub3d");
    cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
    cub.addr = mlx_get_data_addr(cub.img, &cub.bbp, &cub.size_line, &cub.endian);
    mlx_loop_hook(cub.mlx, game_loop, &cub);
    mlx_hook(cub.win, 02, 1L << 0, key_press, &player);
    mlx_hook(cub.win, 03, 1L << 1, key_release, &player);
    mlx_loop(cub.mlx);
    return (0);
}