/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:12:44 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 18:25:44 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    go_right(t_player *player)
{
    double new_x = player->pos_x + player->plane_x * 0.05;
    double new_y = player->pos_y + player->plane_y * 0.05;
    if (player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void    go_left(t_player *player)
{
    double new_x = player->pos_x - player->plane_x * 0.05;
    double new_y = player->pos_y - player->plane_y * 0.05;
    if (player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void    backward(t_player *player)
{
    double new_x = player->pos_x - player->dir_x * 0.05;
    double new_y = player->pos_y - player->dir_y * 0.05;
    if (player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void forward(t_player *player)
{
    double new_x = player->pos_x + player->dir_x * 0.05;
    double new_y = player->pos_y + player->dir_y * 0.05;
    if (player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void    move_player(t_player *player)
{
    if (player->move_up)
        forward(player);
    if (player->move_down)
        backward(player);
    if (player->move_left)
        go_left(player);
    if (player->move_right)
        go_right(player);
}
