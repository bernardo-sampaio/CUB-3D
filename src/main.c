/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:17:16 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/24 17:39:19 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_dda(t_player *player)
{
    player->hit = 0;
    while(player->hit == 0)
    {
        if (player->side_x < player->side_y)
        {
            player->side_x += player->delta_x;
            player->map_x += player->step_x;
            player->side = 0;
        }
        else
        {
            player->side_y += player->delta_y;
            player->map_y += player->step_y;
            player->side = 1;
        }
        if (player->map_x < 0 || player->map_y < 0)
            return;
        if (player->map_x >= player->map_width || player->map_y >= player->map_height)
            return;
        if (!player->map[player->map_y] || !player->map[player->map_y][player->map_x])
            return;
        if (player->map[player->map_y][player->map_x] == '1')
            player->hit = 1;
    }
}

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
    player->delta_x = fabs(1.0 / player->raydir_x);
    player->delta_y = fabs(1.0 / player->raydir_y);
    if (player->raydir_x < 0)
    {
        player->step_x = -1;
        player->side_x = (player->pos_x - player->map_x) * player->delta_x;
    }
    else
    {
        player->step_x = 1;
        player->side_x = (player->map_x + 1.0 - player->pos_x) * player->delta_x;
    }
    if (player->raydir_y < 0)
    {
        player->step_y = -1;
        player->side_y = (player->pos_y - player->map_y) * player->delta_y;
    }
    else
    {
        player->step_y = 1;
        player->side_y = (player->map_y + 1.0 - player->pos_y) * player->delta_y;
    }
    ft_dda(player);
    calculate_walldist(player);
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