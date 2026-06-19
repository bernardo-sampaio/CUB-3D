/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:55:35 by bsampaio          #+#    #+#             */
/*   Updated: 2026/06/19 11:01:15 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_textures(t_cub_bonus *cub, t_text *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub->mlx, path, &tex->w, &tex->h);
	if (!tex->img)
		close_game(cub);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line,
			&tex->endian);
}

void	free_door_weapon(t_cub_bonus *cub, char	*door[], char	*weap, int i)
{
	while (i < 5)
		free(door[i++]);
	free(weap);
	close_game(cub);
}

void	init_textures(t_cub_bonus *cub, t_texture *texture)
{
	int		i;
	char	*door[5];
	char	*weap;

	door[0] = ft_strdup("./sprites/door_00.xpm");
	door[1] = ft_strdup("./sprites/door_02.xpm");
	door[2] = ft_strdup("./sprites/door_04.xpm");
	door[3] = ft_strdup("./sprites/door_06.xpm");
	door[4] = ft_strdup("./sprites/door_10.xpm");
	weap = ft_strdup("./sprites/weapon1.xpm");
	load_textures(cub, cub->north, texture->north_text);
	load_textures(cub, cub->south, texture->south_text);
	load_textures(cub, cub->east, texture->east_text);
	load_textures(cub, cub->west, texture->west_text);
	load_textures(cub, cub->weap, weap);
	i = -1;
	while (++i < 5)
	{
		cub->door[i] = malloc(sizeof(t_text));
		if (!cub->door[i])
			free_door_weapon(cub, door, weap, i);
		load_textures(cub, cub->door[i], door[i]);
		free(door[i]);
	}
	free(weap);
}

t_text	*get_texture(t_cub_bonus *cub)
{
	if (cub->player->hit_door == 1)
	{
		if (cub->player->door_frame < 0 || cub->player->door_frame > 4
			|| !cub->door[cub->player->door_frame])
			return (cub->north);
		return (cub->door[cub->player->door_frame]);
	}
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

int	put_pixel_image(t_cub_bonus *cub, int x, int y, int color)
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
