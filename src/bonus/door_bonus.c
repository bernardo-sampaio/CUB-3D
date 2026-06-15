/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:10:05 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/15 14:23:40 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    update_door(t_cub_bonus *cub)
{
    static int delay;
    int x;
    int y;
    
    delay++;
    if (delay < 6)
        return ;
    delay = 0;
    y = 0;
    while (cub->player->map[y])
    {
        x = 0;
        while (cub->player->map[y][x])
        {
            if (cub->player->map[y][x] >= '2' && cub->player->map[y][x] <= '4')
                cub->player->map[y][x]++;
            else if (cub->player->map[y][x] == '5')
                cub->player->map[y][x] = 'O';
            x++;
        }
        y++;
    }
}

void    open_close_door(t_cub_bonus *cub)
{
    int target_x;
    int target_y;

    target_x =  (int)(cub->player->pos_x + cub->player->dir_x * 1.0);
    target_y =  (int)(cub->player->pos_y + cub->player->dir_y * 1.0);
    if (in_bounds(cub->player, target_x, target_y))
    {
        if (cub->player->map[target_y][target_x] == 'D')
            cub->player->map[target_y][target_x] = '2';
        else if (cub->player->map[target_y][target_x] == 'O' && 
            ((int)cub->player->pos_x != target_x || (int)cub->player->pos_y != target_y))
            cub->player->map[target_y][target_x] = 'D';
    }
}
