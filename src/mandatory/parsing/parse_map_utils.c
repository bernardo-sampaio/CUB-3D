/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:31:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 11:36:11 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while ((line[i] && line[i] == ' ') || (line[i] >= '\t' && line[i] <= '\r'))
		i++;
	if (!line[i])
		return (false);
	while (line[i] && ft_strchr("01NSEW ", line[i]))
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
		if (is_only_whitespace((char *)grasp->content) == false)
		{
			error_msg("Invalid map format: non-map line found after map lines");
			ft_putendl_fd((char *)grasp->content, 2);
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
