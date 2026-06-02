/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:45:46 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/01 18:32:36 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    draw_player(t_cub *cub)
{
    int py;
    int px;
    
    py = -2;
    while (py <= 2)
    {
        px = -2;
        while (px <= 2)
        {
            put_pixel_image(cub, OFFSET_X + (int)(cub->player->pos_x * SCALE_PX) + px, OFFSET_Y + (int)(cub->player->pos_y * SCALE_PX) + py, 0x0000FF00);
            px++;
        }
        py++;
    }
}

void    draw_tile(t_cub *cub, int x, int y, int color)
{
    int py;
    int px;
    
    py = 0;
    while (py < SCALE_PX)
    {
        px = 0;
        while(px < SCALE_PX)
        {
            put_pixel_image(cub, OFFSET_X + x * SCALE_PX + px, OFFSET_Y + y * SCALE_PX + py, color);
            px++;
        }
        py++;
    }
}

void    draw_minimap(t_cub *cub)
{
    int x;
    int y;
    int color;

    draw_player(cub);
    y = -1;
    while (++y < cub->player->map_height)
    {
        x = -1;
        while (++x < cub->player->map_width)
        {
            if (!cub->player->map[y] || !cub->player->map[y][x] || cub->player->map[y][x] == ' ')
            {
                x++;
                continue;
            }
            if (cub->player->map[y][x] == '1')
                color = 0x00FFFFFF;
            else
            {
                x++;
                continue;
            }
            draw_tile(cub, x, y, color);
        }
    }
}
