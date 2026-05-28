/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:12:44 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/28 12:18:49 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int in_bounds(t_player *player, int x, int y)
{
    if (x < 0 || y < 0)
        return (0);
    if (x >= player->map_width || y >= player->map_height)
        return (0);
    if (!player->map[y] || !player->map[y][x])
        return (0);
    return (1);   
}

void    go_right(t_player *player)
{
    double new_x;
    double new_y;
    
    new_x = player->pos_x + player->plane_x * 0.03;
    new_y = player->pos_y + player->plane_y * 0.03;
    if (in_bounds(player, (int)new_x, (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)new_y) &&
         player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void    go_left(t_player *player)
{
    double new_x;
    double new_y;

    new_x = player->pos_x - player->plane_x * 0.03;
    new_y = player->pos_y - player->plane_y * 0.03;
    if (in_bounds(player, (int)new_x, (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)new_y) && 
        player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void    backward(t_player *player)
{
    double new_x;
    double new_y;

    new_x = player->pos_x - player->dir_x * 0.03;
    new_y = player->pos_y - player->dir_y * 0.03;
    if (in_bounds(player, (int)new_x, (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)new_y) && 
        player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}
void forward(t_player *player)
{
    double new_x; 
    double new_y;
     
    new_x = player->pos_x + player->dir_x * 0.03;
    new_y = player->pos_y + player->dir_y * 0.03;
    if (in_bounds(player, (int)new_x, (int)player->pos_y) && 
        player->map[(int)player->pos_y][(int)new_x] != '1')
        player->pos_x = new_x;
    if (in_bounds(player, (int)player->pos_x, (int)new_y) && 
        player->map[(int)new_y][(int)player->pos_x] != '1')
        player->pos_y = new_y;
}

void rotate_right(t_player *player)
{
    double old_dir_x;
    double old_plane_x;
    
    old_dir_x = player->dir_x;
    old_plane_x = player->plane_x;
    player->dir_x = player->dir_x * cos(0.03) - player->dir_y * sin(0.03);
    player->dir_y = old_dir_x * sin(0.03) + player->dir_y * cos(0.03);
    player->plane_x = player->plane_x * cos(0.03) - player->plane_y * sin(0.03);
    player->plane_y = old_plane_x * sin(0.03) + player->plane_y * cos(0.03);
}

void rotate_left(t_player *player)
{
    double old_dir_x;  
    double old_plane_x;
    
    old_dir_x   = player->dir_x;
    old_plane_x = player->plane_x;
    player->dir_x   = player->dir_x * cos(-0.03) - player->dir_y * sin(-0.03);
    player->dir_y   = old_dir_x * sin(-0.03) + player->dir_y * cos(-0.03);
    player->plane_x = player->plane_x * cos(-0.03) - player->plane_y * sin(-0.03);
    player->plane_y = old_plane_x * sin(-0.03) + player->plane_y * cos(-0.03);
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
    if (player->rot_left)
        rotate_left(player);
    if (player->rot_right)
        rotate_right(player);
}


