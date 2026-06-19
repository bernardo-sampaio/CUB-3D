/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:19:22 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/19 11:03:17 by bsampaio         ###   ########.fr       */
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

int	close_game(t_cub_bonus *cub)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (cub->door[i]->img)
			mlx_destroy_image(cub->mlx, cub->door[i]->img);
		free(cub->door[i]);
		i++;
	}
	mlx_destroy_image(cub->mlx, cub->weap->img);
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

void	process_texture(t_player *player, t_render *render)
{
	double	wall_x;

	if (player->side == 0)
		wall_x = player->pos_y + player->walldist * player->raydir_y;
	else
		wall_x = player->pos_x + player->walldist * player->raydir_x;
	wall_x -= floor(wall_x);
	render->tex_x = (int)(wall_x * render->text->w);
	if (player->side == 0 && player->raydir_x < 0)
		render->tex_x = render->text->w - render->tex_x - 1;
	if (player->side == 1 && player->raydir_y > 0)
		render->tex_x = render->text->w - render->tex_x - 1;
	render->step = (double)render->text->h / player->line_height;
	render->tex_pos = (player->drawstart - HEIGHT / 2 + player->line_height / 2)
		* render->step;
}

void	draw_background(t_cub_bonus *cub, t_render *re)
{
	while (re->y < cub->player->drawstart)
	{
		put_pixel_image(cub, re->x, re->y, rgb_to_hex(cub->color->c_rgb[0],
				cub->color->c_rgb[1], cub->color->c_rgb[2]));
		re->y++;
	}
	while (re->y <= cub->player->drawend)
	{
		re->tex_y = (int)re->tex_pos;
		if (re->tex_y < 0)
			re->tex_y = 0;
		if (re->tex_y >= re->text->h)
			re->tex_y = re->text->h - 1;
		re->tex_pos += re->step;
		re->color = *(int *)(re->text->addr + re->tex_y * re->text->size_line
				+ re->tex_x * (re->text->bpp / 8));
		put_pixel_image(cub, re->x, re->y, re->color);
		re->y++;
	}
	while (re->y < HEIGHT)
	{
		put_pixel_image(cub, re->x, re->y, rgb_to_hex(cub->color->f_rgb[0],
				cub->color->f_rgb[1], cub->color->f_rgb[2]));
		re->y++;
	}
}

int	render_frame(t_cub_bonus *cub)
{
	t_render	*render;

	render = cub->render;
	render->x = 0;
	while (render->x < WIDTH)
	{
		calculate_raydir(cub->player, render->x, WIDTH);
		setup_dda(cub->player);
		cub->player->hit = 0;
		cub->player->hit_door = 0;
		ft_dda(cub->player);
		calculate_walldist(cub->player);
		if (cub->player->line_height <= 0)
			cub->player->line_height = 1;
		render->text = get_texture(cub);
		process_texture(cub->player, render);
		render->y = 0;
		draw_background(cub, render);
		render->x++;
	}
	draw_weapon(cub);
	draw_minimap(cub);
	return (0);
}
