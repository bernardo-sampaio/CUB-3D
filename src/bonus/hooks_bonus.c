/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:21:31 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/15 14:23:15 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int key_press(int key, t_cub_bonus *cub)
{
    if (key == 119)
    {
        cub->player->move_up = 1;
        cub->player->is_moving = 1;   
    }
    if (key == 115)
        cub->player->move_down = 1;
    if (key == 100)
        cub->player->move_right = 1;
    if (key == 97)
        cub->player->move_left = 1;
    if (key == 65361)
        cub->player->rot_left = 1;
    if (key == 65363)
        cub->player->rot_right = 1;
    if (key == 32)
        open_close_door(cub);
    return (0);
}
int key_release(int key, t_cub_bonus *cub)
{
    if (key == 119)
    {
        cub->player->move_up = 0;
        cub->player->is_moving = 0;
    }
    if (key == 115)
        cub->player->move_down = 0;
    if (key == 100)
        cub->player->move_right = 0;
    if (key == 97)
        cub->player->move_left = 0;
    if (key == 65361)
        cub->player->rot_left = 0;
    if (key == 65363)
        cub->player->rot_right = 0;
    if (key == 65307)
        close_game(cub);
    return (0);
}

int mouse_move(int x, int y, t_cub_bonus *cub)
{
    int center_x;
    int delta_x;

    (void)y;
    center_x = WIDTH / 2;
    delta_x = x - center_x;
    if (delta_x == 0)
        return (0);
    rotate_player(cub->player, delta_x * 0.001);
    mlx_mouse_move(cub->mlx, cub->win, center_x, HEIGHT / 2);
    return (0);
}
