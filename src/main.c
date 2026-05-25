/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:17:16 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 13:51:21 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    calculate_walldist(t_player *player)
{
    if (player->side == 0)
        player->walldist = (player->side_x - player->delta_x);
    else
        player->walldist = (player->side_y - player->delta_y);
    player->line_height = (int)(HEIGHT / player->walldist);
    player->drawstart = -player->line_height / 2 + HEIGHT / 2;
    if (player->drawstart < 0)
        player->drawstart = 0;
    player->drawend = player->line_height / 2 + HEIGHT / 2;
    if (player->drawend >= HEIGHT)
        player->drawend = HEIGHT - 1;
}

void    calculate_raydir(t_player *player, int x, int widthscreen)
{
    double camera_x;
    
    player->map_x = (int)player->pos_x;
    player->map_y = (int)player->pos_y;
    camera_x = 2 * x / (double)widthscreen - 1;
    player->raydir_x = player->dir_x + player->plane_x * camera_x;
    player->raydir_y = player->dir_y + player->plane_y * camera_x;
}


int main(int ac, char **av)
{
    t_cub   cub;
    t_player player;

    if (ac != 2)
        return (1);
    
    player.map = ft_get_map(&player, av[1]);
    initialize_player(&player);
    calculate_raydir(&player, 0, WIDTH);
    printf("%f", player.walldist);
    cub.mlx = mlx_init();
    cub.win = mlx_new_window(cub.mlx,  WIDTH, HEIGHT, "cub3d");
    cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
    cub.addr = mlx_get_data_addr(cub.img, &cub.bbp, &cub.size_line, &cub.endian);
    render_frame(&cub, &player);
    //mlx_loop_hook(cub.mlx, render_frame, &player);
    mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
    mlx_loop(cub.mlx);
    return (0);
}