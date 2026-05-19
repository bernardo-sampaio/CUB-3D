/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:07:42 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 14:07:43 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

static bool	ft_isspace(int c)
{
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;

	if (!line[i])
		return (false);

	while (line[i] && ft_strchr("01NSEW ", line[i]))
		i++;

	if (line[i] == '\0' || line[i] == '\n')
		return (true);

	return (false);
}

static int count_map_lines(t_file *file)
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

static bool load_grid(t_file *file, t_map *map)
{
    t_list    *head;
    int       index;

    map->grid = ft_calloc(map->height + 1, sizeof(char *));
    if (!map->grid)
        return (error_msg("Memory allocation failed\n"), false); //should we use strerror here?
    map->width = 0;
    index = 0;
    head = file->lines;
    while (head)
    {
        if (is_map_line((char *)head->content))
        {
            map->grid[index] = ft_strdup((char *)head->content);
            if (!map->grid[index])
            {
                free_mat(map->grid);
                return (error_msg("Memory allocation failed\n"), false);
            }
            if ((int)ft_strlen(map->grid[index]) > map->width)
                map->width = ft_strlen(map->grid[index]) - 1; // -1 to ignore the newline character
            index++;
        }
        head = head->next;
    }
    return (true);
}

bool check_map(t_file *file, t_map *map)
{
    map->height = count_map_lines(file);
    if (map->height == 0)
        return (error_msg("No map found in the file\n"), false);
    load_grid(file, map);
    int i = 0;
    while (i < map->height)
    {
        printf("%s", map->grid[i]);
        i++;
    }
    return (true);
}