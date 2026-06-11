/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:39:14 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/11 14:33:34 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    draw_weapon(t_cub *cub)
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
