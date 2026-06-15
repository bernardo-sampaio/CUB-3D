/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:12:44 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/15 15:33:49 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    go_right(t_player *player)
{
    double new_x;
    double new_y;
    double margin_x;
    double margin_y;
    
    new_x = player->pos_x + player->plane_x * 0.05;
    new_y = player->pos_y + player->plane_y * 0.05;
    if (player->plane_x > 0)
        margin_x = 0.2;
    else
        margin_x = -0.2;
    if (player->plane_y > 0)
        margin_y = 0.2;
    else
        margin_y = -0.2;
    if (in_bounds(player, (int)(new_x + margin_x), (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)(new_x + margin_x)] == '0')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)(new_y + margin_y)) &&
         player->map[(int)(new_y + margin_y)][(int)player->pos_x] == '0')
        player->pos_y = new_y;
}

static  void    go_left(t_player *player)
{
    double new_x;
    double new_y;
    double margin_x;
    double margin_y;

    new_x = player->pos_x - player->plane_x * 0.05;
    new_y = player->pos_y - player->plane_y * 0.05;
    if (player->plane_x > 0)
        margin_x = -0.2;
    else
        margin_x = 0.2;
    if (player->plane_y > 0)
        margin_y = -0.2;
    else
        margin_y = 0.2;
    if (in_bounds(player, (int)(new_x + margin_x), (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)(new_x + margin_x)] == '0')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)(new_y + margin_y)) && 
        player->map[(int)(new_y + margin_y)][(int)player->pos_x] == '0')
        player->pos_y = new_y;
}
static  void    backward(t_player *player)
{
    double new_x;
    double new_y;
    double margin_x;
    double margin_y;

    new_x = player->pos_x - player->dir_x * 0.05;
    new_y = player->pos_y - player->dir_y * 0.05;
    if (player->dir_x > 0)
        margin_x = -0.2;
    else
        margin_x = 0.2;
    if (player->dir_y > 0)
        margin_y = -0.2;
    else
        margin_y = 0.2;
    if (in_bounds(player, (int)(new_x + margin_x), (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)(new_x + margin_x)] == '0')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)(new_y + margin_y)) && 
        player->map[(int)(new_y + margin_y)][(int)player->pos_x] == '0')
        player->pos_y = new_y;
}
static  void forward(t_player *player)
{
    double new_x; 
    double new_y;
    double margin_x;
    double margin_y;
     
    new_x = player->pos_x + player->dir_x * 0.05;
    new_y = player->pos_y + player->dir_y * 0.05;
    if (player->dir_x > 0)
        margin_x = 0.2;
    else
        margin_x = -0.2;
    if (player->dir_y > 0)
        margin_y = 0.2;
    else
        margin_y = -0.2;
    if (in_bounds(player, (int)(new_x + margin_x), (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)(new_x + margin_x)] == '0')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)(new_y + margin_y)) && 
        player->map[(int)(new_y + margin_y)][(int)player->pos_x] == '0')
        player->pos_y = new_y;
}

void    move_player(t_cub *cub)
{
    if (cub->player->move_up)
        forward(cub->player);
    if (cub->player->move_down)
        backward(cub->player);
    if (cub->player->move_left)
        go_left(cub->player);
    if (cub->player->move_right)
        go_right(cub->player);
    if (cub->player->rot_left)
        rotate_left(cub->player);
    if (cub->player->rot_right)
        rotate_right(cub->player);
}


