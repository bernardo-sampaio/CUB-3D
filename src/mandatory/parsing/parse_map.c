/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:07:42 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 11:33:26 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

static bool	load_grid(t_file *file, t_map *map)
{
	t_list		*head;
	static int	index;

	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (map->grid == NULL)
		return (error_msg("Memory allocation failed"), false);
	head = file->lines;
	while (head)
	{
		if (is_map_line((char *)head->content, "01NSEW "))
		{
			map->grid[index] = ft_strdup((char *)head->content);
			if (map->grid[index] == NULL)
				return (error_msg("Memory allocation failed"), false);
			if ((int)ft_strlen(map->grid[index]) > map->width)
				map->width = ft_strlen(map->grid[index]) - 1;
			index++;
		}
		else if (index > 0)
			if (after_map(head) == false)
				return (false);
		head = head->next;
	}
	return (true);
}

static bool	normalize_grid(t_map *map)
{
	char	*normalized_line;
	int		i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) - 1 < map->width)
		{
			normalized_line = ft_calloc(map->width + 2, sizeof(char));
			if (normalized_line == NULL)
				return (error_msg("Memory allocation failed"), false);
			copy_grid(map, i, normalized_line);
		}
		i++;
	}
	return (true);
}

static bool	tell_ma_gossip(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == '0' || map->grid[i][j] == 'N'
				|| map->grid[i][j] == 'S' || map->grid[i][j] == 'E'
				|| map->grid[i][j] == 'W')
			{
				if ((j <= map->width - 1 && map->grid[i][j + 1] == ' ')
					|| (j > 0 && map->grid[i][j - 1] == ' ')
					|| (i <= map->height - 1 && map->grid[i + 1][j] == ' ')
					|| (i > 0 && map->grid[i - 1][j] == ' '))
					return (for_gossip(map->grid[i][j], i, j), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	is_surrounded_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			{
				if (map->grid[i][j] != '1' && map->grid[i][j] != ' ')
				{
					for_walls(i, j);
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map(t_file *file, t_map *map)
{
	map->height = count_map_lines(file);
	if (map->height == 0)
		return (error_msg("No map found in the file"), false);
	if (load_grid(file, map) == false)
		return (false);
	if (map->height <= 3 && map->width <= 3)
		return (error_msg("Map too small"), false);
	if (normalize_grid(map) == false)
		return (false);
	if (is_valid_char(map) == false)
		return (false);
	if (map->tiles.player != 1)
	{
		error_msg("Map must contain exactly one player");
		return (false);
	}
	if (is_surrounded_by_walls(map) == false)
		return (false);
	if (tell_ma_gossip(map) == false)
		return (false);
	return (true);
}
