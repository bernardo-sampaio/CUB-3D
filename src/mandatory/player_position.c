/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:45:30 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/17 18:27:45 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inicialize_north(t_player *player, int x, int y)
{
	player->pos_x = (double)x + 0.5;
	player->pos_y = (double)y + 0.5;
	player->dir_x = 0.0;
	player->dir_y = -1.0;
	player->plane_x = 0.66;
	player->plane_y = 0.0;
	player->map[y][x] = '0';
	player->move_down = 0;
	player->move_up = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->rot_left = 0;
	player->rot_right = 0;
}

void	inicialize_south(t_player *player, int x, int y)
{
	player->pos_x = (double)x + 0.5;
	player->pos_y = (double)y + 0.5;
	player->dir_x = 0.0;
	player->dir_y = 1.0;
	player->plane_x = -0.66;
	player->plane_y = 0.0;
	player->map[y][x] = '0';
	player->move_down = 0;
	player->move_up = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->rot_left = 0;
	player->rot_right = 0;
}

void	inicialize_weast(t_player *player, int x, int y)
{
	player->pos_x = (double)x + 0.5;
	player->pos_y = (double)y + 0.5;
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = -0.66;
	player->map[y][x] = '0';
	player->move_down = 0;
	player->move_up = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->rot_left = 0;
	player->rot_right = 0;
}

void	inicialize_east(t_player *player, int x, int y)
{
	player->pos_x = (double)x + 0.5;
	player->pos_y = (double)y + 0.5;
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	player->map[y][x] = '0';
	player->move_down = 0;
	player->move_up = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->rot_left = 0;
	player->rot_right = 0;
}

void	initialize_player(t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (player->map[y])
	{
		x = 0;
		while (player->map[y][x])
		{
			if (player->map[y][x] == 'N')
				inicialize_north(player, x, y);
			else if (player->map[y][x] == 'S')
				inicialize_south(player, x, y);
			else if (player->map[y][x] == 'E')
				inicialize_east(player, x, y);
			else if (player->map[y][x] == 'W')
				inicialize_weast(player, x, y);
			x++;
		}
		y++;
	}
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
}
