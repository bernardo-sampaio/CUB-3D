/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:01:04 by bsampaio          #+#    #+#             */
/*   Updated: 2026/05/25 17:25:22 by bsampaio         ###   ########.fr       */
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

int    render_frame(t_cub *cub)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        calculate_raydir(cub->player, x, WIDTH);
        setup_dda(cub->player);
        ft_dda(cub->player);
        calculate_walldist(cub->player);
        y = 0;
        while (y < HEIGHT)
        {
            if (y < cub->player->drawstart)
                put_pixel_image(cub, x, y, SKY_BULE_COLOR);
            else if (y >= cub->player->drawstart && y <= cub->player->drawend)
                put_pixel_image(cub, x, y,  WALL_COLOR);
            else
                put_pixel_image(cub, x, y, BROWN_C0LOR);
            y++;
        }
        x++;
    }
    return (0);
}
