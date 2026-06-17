/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:33:33 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/17 19:33:48 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_cub *cub, t_text *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub->mlx, path, &tex->w, &tex->h);
	if (!tex->img)
		close_game(cub);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line,
			&tex->endian);
}

void	init_textures(t_cub *cub, t_texture *texture)
{
	load_textures(cub, cub->north, texture->north_text);
	load_textures(cub, cub->south, texture->south_text);
	load_textures(cub, cub->east, texture->east_text);
	load_textures(cub, cub->west, texture->west_text);
}

t_text	*get_texture(t_cub *cub)
{
	if (cub->player->side == 0)
	{
		if (cub->player->raydir_x > 0)
			return (cub->west);
		else
			return (cub->east);
	}
	else
	{
		if (cub->player->raydir_y > 0)
			return (cub->south);
		else
			return (cub->north);
	}
}

int	put_pixel_image(t_cub *cub, int x, int y, int color)
{
	int	res;

	if (x < 0 || x >= WIDTH)
		return (0);
	if (y < 0 || y >= HEIGHT)
		return (0);
	res = (y * cub->size_line) + (x * (cub->bpp / 8));
	*(int *)(cub->addr + res) = color;
	return (1);
}