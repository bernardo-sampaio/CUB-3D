/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:59:44 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/19 09:44:32 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_walldist(t_player *player)
{
	if (player->side == 0)
		player->walldist = (player->side_x - player->delta_x);
	else
		player->walldist = (player->side_y - player->delta_y);
	if (player->walldist < 0.0001)
		player->walldist = 0.0001;
	player->line_height = (int)(HEIGHT / player->walldist);
	if (player->line_height <= 0)
		player->line_height = 1;
	player->drawstart = -player->line_height / 2 + HEIGHT / 2;
	if (player->drawstart < 0)
		player->drawstart = 0;
	player->drawend = player->line_height / 2 + HEIGHT / 2;
	if (player->drawend >= HEIGHT)
		player->drawend = HEIGHT - 1;
}

void	calculate_raydir(t_player *player, int x, int widthscreen)
{
	double	camera_x;

	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	camera_x = 2 * x / (double)widthscreen - 1;
	player->raydir_x = player->dir_x + player->plane_x * camera_x;
	player->raydir_y = player->dir_y + player->plane_y * camera_x;
}
