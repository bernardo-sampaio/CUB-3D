/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:01:04 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/24 17:37:59 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    put_pixel_image(t_cub *cub, int x, int y, int color)
{
    int res;
    
    if (x < 0 || x >= WIDTH)
        return (0);
    if (y < 0 || y >= HEIGHT)
        return (0);
    res = (y * cub->size_line) + (x * (cub->bbp / 8));
    *(int *)(cub->addr + res) = color;
    return (1);
}

int    render_frame(t_cub *cub, t_player *player)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        calculate_raydir(player, x, WIDTH);
        y = 0;
        while (y < HEIGHT)
        {
            if (y < player->drawstart)
                put_pixel_image(cub, x, y, SKY_BULE_COLOR);
            else if (y >= player->drawstart && y <= player->drawend)
                put_pixel_image(cub, x, y,  WALL_COLOR);
            else
                put_pixel_image(cub, x, y, BROWN_C0LOR);
            y++;
        }
        x++;
    }
    return (0);
}
