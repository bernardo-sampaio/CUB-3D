/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:36:54 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/17 19:37:31 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_cub *cub)
{
	move_player(cub);
	mlx_clear_window(cub->mlx, cub->win);
	render_frame(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

int	close_game(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->north->img);
	mlx_destroy_image(cub->mlx, cub->south->img);
	mlx_destroy_image(cub->mlx, cub->east->img);
	mlx_destroy_image(cub->mlx, cub->west->img);
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
