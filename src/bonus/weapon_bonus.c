/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:13:13 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/15 14:54:28 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    draw_weapon(t_cub_bonus *cub)
{
    int x;
    int y;
    int color;
    int start_x;
    int start_y;
    int offset_y;
    
    if (cub->player->is_moving == 1)
        cub->player->weapon_timer += 0.17;
    offset_y =  sin(cub->player->weapon_timer) * 20;
    start_x = (WIDTH / 2) - (cub->weap->w / 2);
    start_y = (HEIGHT - cub->weap->h) + offset_y;
    x = 0;
    while(x < cub->weap->w)
    {
        y = 0;
        while(y < cub->weap->h)
        {
            color = *(int *)(cub->weap->addr + y * cub->weap->size_line + x * (cub->weap->bpp / 8));
            if (color > 0)
                put_pixel_image(cub, start_x + x, start_y + y, color);
            y++;
        }
        x++;
    }
}
