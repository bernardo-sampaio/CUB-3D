/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:20:13 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/19 11:32:18 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	game_loop(t_cub_bonus *cub)
{
	move_player(cub);
	mlx_clear_window(cub->mlx, cub->win);
	update_door(cub);
	render_frame(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

void	destroy_images(t_cub_bonus *cub)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (cub->door[i])
		{
			if (cub->door[i]->img)
				mlx_destroy_image(cub->mlx, cub->door[i]->img);
			free(cub->door[i]);
		}
		i++;
	}
	if (cub->weap && cub->weap->img)
		mlx_destroy_image(cub->mlx, cub->weap->img);
	if (cub->north && cub->north->img)
		mlx_destroy_image(cub->mlx, cub->north->img);
	if (cub->south && cub->south->img)
		mlx_destroy_image(cub->mlx, cub->south->img);
	if (cub->east && cub->east->img)
		mlx_destroy_image(cub->mlx, cub->east->img);
	if (cub->west && cub->west->img)
		mlx_destroy_image(cub->mlx, cub->west->img);
}

int	close_game(t_cub_bonus *cub)
{
	destroy_images(cub);
	free_structs(cub->cub3d);
	if (cub && cub->mlx && cub->img)
		mlx_destroy_image(cub->mlx, cub->img);
	if (cub && cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub && cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(1);
	return (0);
}
