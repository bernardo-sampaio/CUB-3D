/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:20:26 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/27 12:20:27 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

void	init_color(t_color *color, char *ident, char **content)
{
	if (ident[0] == 'F')
	{
		if (color->floor_rgb == NULL)
			color->floor_rgb = ft_calloc(3, sizeof(int));
		color->floor_rgb[0] = ft_atoi(content[0]);
		color->floor_rgb[1] = ft_atoi(content[1]);
		color->floor_rgb[2] = ft_atoi(content[2]);
	}
	if (ident[0] == 'C')
	{
		if (color->ceiling_rgb == NULL)
			color->ceiling_rgb = ft_calloc(3, sizeof(int));
		color->ceiling_rgb[0] = ft_atoi(content[0]);
		color->ceiling_rgb[1] = ft_atoi(content[1]);
		color->ceiling_rgb[2] = ft_atoi(content[2]);
	}
}

bool	validate_range(char **mat)
{
	int	i;
	int	nbr;

	i = 0;
	while (mat[i])
	{
		nbr = ft_atoi(mat[i]);
		if (nbr < 0 || nbr > 255)
			return (false);
		i++;
	}
	return (true);
}

bool	after_space(char **mat, int i, int j)
{
	while (mat[i][j])
	{
		if (mat[i][j] != ' ' && mat[i][j] != '\n' && mat[i][j] != ',')
			return (false);
		j++;
	}
	return (true);
}

bool	all_digit(char **mat)
{
	int	i;
	int	j;

	i = 0;
	while (mat && mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (ft_isdigit(mat[i][j]) != 1 && mat[i][j] != '\n')
			{
				if (j != 0 && ft_isdigit(mat[i][j]) != 1 && mat[i][j] != ' ')
					return (false);
				if (mat[i][j] == ' ' && after_space(mat, i, j) == false)
				{
					if (j != 0 && ft_isdigit(mat[i][j - 1]))
						return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_chars(char *color)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while (color[i])
	{
		if (ft_isdigit(color[i]) == 1 && (color[i + 1] == ','
				|| color[i + 1] == ' ' || color[i + 1] == '\n'))
			nbr++;
		if (ft_isdigit(color[i]) != 1 && color[i] != ',' && color[i] != ' '
			&& color[i] != '\n')
			return (error_msg("Invalid color"), false);
		i++;
	}
	if (nbr != 3)
		return (error_msg("Invalid color"), false);
	return (true);
}
