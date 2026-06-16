/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:48:39 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:11:22 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing_bonus.h"

void	free_mat(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

void	free_texture(t_texture *texture_dir)
{
	free(texture_dir->north_text);
	free(texture_dir->south_text);
	free(texture_dir->west_text);
	free(texture_dir->east_text);
}

void	free_color(t_color *color)
{
	free(color->floor_rgb);
	free(color->ceiling_rgb);
}

void	free_structs(t_cub3d *cub3d)
{
	ft_lstclear(&cub3d->file.lines, free);
	free_texture(&cub3d->texture);
	free_color(&cub3d->color);
	if (cub3d->map.grid != NULL)
		free_mat(cub3d->map.grid);
}
