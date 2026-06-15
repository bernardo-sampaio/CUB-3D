/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:28:56 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/12 11:29:14 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void    rotate_player(t_player *player, double angle)
{
    double old_dir_x;
    double old_plane_x;
    
    old_dir_x = player->dir_x;
    old_plane_x = player->plane_x;
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
    player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
    player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void rotate_right(t_player *player)
{
    rotate_player(player, 0.05);
}

void rotate_left(t_player *player)
{
    rotate_player(player, -0.05);
}