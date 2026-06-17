/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:49:41 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/17 15:09:36 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step_and_side(t_player *player)
{
	if (player->raydir_x < 0)
	{
		player->step_x = -1;
		player->side_x = (player->pos_x - player->map_x) * player->delta_x;
	}
	else
	{
		player->step_x = 1;
		player->side_x = (player->map_x + 1.0 - player->pos_x)
			* player->delta_x;
	}
	if (player->raydir_y < 0)
	{
		player->step_y = -1;
		player->side_y = (player->pos_y - player->map_y) * player->delta_y;
	}
	else
	{
		player->step_y = 1;
		player->side_y = (player->map_y + 1.0 - player->pos_y)
			* player->delta_y;
	}
}

void	setup_dda(t_player *player)
{
	if (player->raydir_x == 0)
		player->delta_x = 1e30;
	else
		player->delta_x = fabs(1.0 / player->raydir_x);
	if (player->raydir_y == 0)
		player->delta_y = 1e30;
	else
		player->delta_y = fabs(1.0 / player->raydir_y);
	step_and_side(player);
}

void	dda_step(t_player *player)
{
	if (player->side_x < player->side_y)
	{
		player->side_x += player->delta_x;
		player->map_x += player->step_x;
		player->side = 0;
	}
	else
	{
		player->side_y += player->delta_y;
		player->map_y += player->step_y;
		player->side = 1;
	}
	if (player->map_x < 0 || player->map_y < 0
		|| player->map_x >= player->map_width
		|| player->map_y >= player->map_height)
	{
		player->walldist = 1e30;
		return ;
	}
	if (!player->map[player->map_y]
		|| !player->map[player->map_y][player->map_x])
	{
		player->walldist = 1e30;
		return ;
	}
}

void	ft_dda(t_player *player)
{
	player->hit = 0;
	while (player->hit == 0)
	{
		dda_step(player);
		if (player->map[player->map_y][player->map_x] == '1')
			player->hit = 1;
	}
}
