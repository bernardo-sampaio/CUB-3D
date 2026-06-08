/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:31:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/08 16:23:23 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (false);
	while (line[i] && ft_strchr("01NSEWD ", line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (true);
	return (false);
}

int	count_map_lines(t_file *file)
{
	t_list	*head;
	int		count;

	head = file->lines;
	count = 0;
	while (head)
	{
		if (is_map_line((char *)head->content))
			count++;
		head = head->next;
	}
	return (count);
}

bool	after_map(t_list *map)
{
	t_list	*grasp;

	grasp = map;
	while (grasp)
	{
		if (is_map_line((char *)grasp->content))
		{
			error_msg("Invalid map format: non-map line found after map lines");
			return (false);
		}
		else if (is_only_whitespace((char *)grasp->content) == false)
		{
			error_msg("Invalid map format: non-map line found after map lines");
			return (false);
		}
		grasp = grasp->next;
	}
	return (true);
}

void	copy_grid(t_map *map, int index, char *normalized_line)
{
	int	j;

	ft_strlcpy(normalized_line, map->grid[index], ft_strlen(map->grid[index])
		+ 1);
	j = ft_strlen(map->grid[index]) - 1;
	while (j < map->width)
	{
		normalized_line[j] = ' ';
		j++;
	}
	normalized_line[map->width] = '\n';
	free(map->grid[index]);
	map->grid[index] = normalized_line;
}

bool	is_valid_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
				map->tiles.player++;
			else if (map->grid[i][j] != '0' && map->grid[i][j] != '1'
				&& map->grid[i][j] != '\n' && map->grid[i][j] != ' ' && map->grid[i][j] != 'D')
			{
				free_mat(map->grid);
				return (error_msg("Invalid char in map"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
