/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:33:32 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/21 12:07:39 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

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

static bool	validate_range(char **mat)
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

static bool	after_space(char **mat, int i, int j)
{
	while (mat[i][j])
	{
		if (mat[i][j] != ' ' && mat[i][j] != '\n' && mat[i][j] != ',')
			return (false);
		j++;
	}
	return (true);
}

static bool	all_digit(char **mat)
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

static bool	check_comma_pos(char *color, int index)
{
	int		i;
	bool	first;
	bool	last;

	first = false;
	i = 0;
	while (i < index)
	{
		if (ft_isdigit(color[i]))
		{
			first = true;
			break ;
		}
		i++;
	}
	last = false;
	i = index;
	while (color[i])
	{
		if (ft_isdigit(color[i]))
		{
			last = true;
			break ;
		}
		i++;
	}
	if (first && last)
		return (true);
	return (false);
}

static bool	count_comma(char *color)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (color && color[i])
	{
		if (color[i] == ',')
		{
			if (check_comma_pos(color, i) == false)
			{
				error_msg("After/Before comma [,] should have a number");
				return (false);
			}
			count++;
		}
		i++;
	}
	if (count == 2)
		return (true);
	error_msg("Invalid color");
	return (false);
}

static char	*remove_first_char(char *content)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc(ft_strlen(content), sizeof(char));
	if (new == NULL)
		return (NULL);
	if ((content[0] == 'F' || content[0] == 'C') && content[1] == ' ')
	{
		j = 0;
		i = 1;
		while (content[i])
		{
			new[j] = content[i];
			i++;
			j++;
		}
	}
	else
		return (free(new), NULL);
	return (new);
}

static bool	extract_ident(t_file *file, t_color *color)
{
	t_list	*head;
	char	**mat;
	char	*pick_c;
	int		count;

	count = 1;
	head = file->lines;
	while (head)
	{
		if (ft_strlen((char *)head->content) == 2)
		{
			pick_c = ft_strdup((char *)head->content);
			if (pick_c == NULL)
				return (error_msg("Memory allocation failed"), false);
			if (pick_c[0] == 'F' || pick_c[0] == 'C')
				count++;
			free(pick_c);
		}
		pick_c = remove_first_char((char *)head->content);
		if (pick_c != NULL)
		{
			if (count_comma(pick_c) == false)
				return (free(pick_c), false);
			mat = ft_split(pick_c, ',');
		}
		if (pick_c != NULL)
		{
			if (count > 2)
			{
				free_mat(mat);
				free(pick_c);
				return (error_msg("Duplicate colors"), false);
			}
			if (all_digit(mat) == false)
			{
				free(pick_c);
				free_mat(mat);
				return (error_msg("Color should be just number [0 - 9]"),
					false);
			}
			if (validate_range(mat) == false)
			{
				free(pick_c);
				free_mat(mat);
				return (error_msg("Color's range should be between [0 - 255]"),
					false);
			}
			init_color(color, (char *)head->content, mat);
			count++;
			free(pick_c);
			free_mat(mat);
		}
		head = head->next;
	}
	if (--count < 2)
		return (error_msg("Miss color in the file [F or C]\n"), false);
	return (true);
}

bool	check_color(t_file *file, t_color *color)
{
	if (extract_ident(file, color) == false)
		return (false);
	return (true);
}
