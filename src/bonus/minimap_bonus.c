/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:12:33 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/19 10:41:28 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_player(t_cub_bonus *cub)
{
	int	py;
	int	px;

	py = -2;
	while (py <= 2)
	{
		px = -2;
		while (px <= 2)
		{
			put_pixel_image(cub, OFFSET_X + (int)(cub->player->pos_x * SCALE_PX)
				+ px, OFFSET_Y + (int)(cub->player->pos_y * SCALE_PX) + py,
				0x0000FF00);
			px++;
		}
		py++;
	}
}

static void	draw_tile(t_cub_bonus *cub, int x, int y, int color)
{
	int	py;
	int	px;

	py = 0;
	while (py < SCALE_PX)
	{
		px = 0;
		while (px < SCALE_PX)
		{
			put_pixel_image(cub, OFFSET_X + x * SCALE_PX + px, OFFSET_Y + y
				* SCALE_PX + py, color);
			px++;
		}
		py++;
	}
}

void	draw_minimap(t_cub_bonus *cub)
{
	t_bonus	min;

	min.y = -1;
	while (++min.y < cub->player->map_height)
	{
		min.x = -1;
		while (++min.x < cub->player->map_width)
		{
			if (!cub->player->map[min.y] || !cub->player->map[min.y][min.x])
				break ;
			if (cub->player->map[min.y][min.x] == '1')
				min.color = 0x00FFFFFF;
			else if (cub->player->map[min.y][min.x] == '0')
				min.color = 0x40000000;
			else if (cub->player->map[min.y][min.x] == 'D')
				min.color = 0x0033FF;
			else if (cub->player->map[min.y][min.x] == 'O')
				min.color = 0x4000001F;
			else
				continue ;
			draw_tile(cub, min.x, min.y, min.color);
		}
	}
	draw_player(cub);
}
