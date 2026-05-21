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

static bool after_map(t_list *map)
{
    t_list *grasp;

    grasp = map;
    while (grasp)
    {
        if (is_map_line((char *)grasp->content))
            return (error_msg("Invalid map format: non-map line found after map lines"), false);
        else if (is_only_whitespace((char *)grasp->content) == false)
            return (error_msg("Invalid map format: non-map line found after map lines"), false);
        grasp = grasp->next;
    }
    return (true);
}

static bool load_grid(t_file *file, t_map *map)
{
    t_list    *head;
    int       index;

    map->grid = ft_calloc(map->height + 1, sizeof(char *));
    if (!map->grid)
        return (error_msg("Memory allocation failed"), false); //should we use strerror here?
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
                return (error_msg("Memory allocation failed"), false);
            }
            if ((int)ft_strlen(map->grid[index]) > map->width)
                map->width = ft_strlen(map->grid[index]) - 1; // -1 to ignore the newline character
            index++;
        }
        else if (index > 0)
            if (after_map(head) == false)
                return (free_mat(map->grid), false);
        head = head->next;
    }
    return (true);
}

static bool normalize_grid(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        if ((int)ft_strlen(map->grid[i]) - 1 < map->width) // -1 to ignore the newline character
        {
            char *normalized_line = ft_calloc(map->width + 2, sizeof(char)); // +2 for newline and null terminator
            if (normalized_line == NULL)
            {
                free(normalized_line);
                return (free_mat(map->grid), error_msg("Memory allocation failed"), false);
            }
            ft_strlcpy(normalized_line, map->grid[i], ft_strlen(map->grid[i]) + 1);
            for (int j = ft_strlen(map->grid[i]) - 1; j < map->width; j++)
                normalized_line[j] = ' ';
            normalized_line[map->width] = '\n';
            normalized_line[map->width + 1] = '\0';
            free(map->grid[i]);
            map->grid[i] = normalized_line;
        }
        i++;
    }
    return (true);
}

static bool	is_valid_char(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (map->grid[i][j])
        {
            if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
                || map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
                map->tiles.player++;
            else if (map->grid[i][j] != '0' && map->grid[i][j] != '1' && map->grid[i][j] != '\n' && map->grid[i][j] != ' ')
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

static bool before_space(t_map *map, int i, int j)
{
    int back;
    int forward;

    back = j - 1;
    while (back >= 0)
    {
        if (map->grid[i][back] == '0' || map->grid[i][back] == 'N' || map->grid[i][back] == 'S'
            || map->grid[i][back] == 'E' || map->grid[i][back] == 'W')
        {
            free_mat(map->grid);
            return (error_msg("Map not closed by walls"), false);
        }
        else if (map->grid[i][back] == '1')
            break ;   
        back--;
    }
    forward = i + 1;
    if (forward >= map->height)
        return (true);
    while (map->grid[forward][j])
    {
        if (map->grid[forward][j] == '0' || map->grid[forward][j] == 'N' || map->grid[forward][j] == 'S'
            || map->grid[forward][j] == 'E' || map->grid[forward][j] == 'W')
        {
            free_mat(map->grid);
         
            return (error_msg("Map not closed by walls"), false);
        }
        else if (map->grid[forward][j] == '1')
            return (true);
        forward++;
    }
    return (true);
}

static bool after_space(t_map *map, int i, int j)
{
	int	back;
	int	up;

	back = j + 1;
	while (map->grid[i][back])
	{
		if (map->grid[i][back] == '0'
			|| map->grid[i][back] == 'N'
			|| map->grid[i][back] == 'S'
			|| map->grid[i][back] == 'E'
			|| map->grid[i][back] == 'W')
		{
			free_mat(map->grid);
			return (error_msg("Map not closed by walls"), false);
		}
		else if (map->grid[i][back] == '1')
			break ;
		back++;
	}
	up = i - 1;
	if (up < 0)
		return (true);
	while (up >= 0)
	{
		if (map->grid[up][j] == '0'
			|| map->grid[up][j] == 'N'
			|| map->grid[up][j] == 'S'
			|| map->grid[up][j] == 'E'
			|| map->grid[up][j] == 'W')
		{
			free_mat(map->grid);
			return (error_msg("Map not closed by walls"), false);
		}
		else if (map->grid[up][j] == '1')
			return (true);
		up--;
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
                if (map->grid[i][j] == ' ')
                {
                    if (before_space(map, i, j) == false)
                        return (false);
                    if (after_space(map, i, j) == false)
                        return (false);
                    j++;
                    continue;
                }
                if (map->grid[i][j] != '1' && map->grid[i][j] != ' ')
                {
                    free_mat(map->grid);
                    return (error_msg("Map not closed by walls"), false);
                }
            }
			j++;
		}
		i++;
	}
	return (true);
}

bool check_map(t_file *file, t_map *map)
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
        free_mat(map->grid);
        error_msg("Map must contain exactly one player");
        return (false);
    }
    if (is_surrounded_by_walls(map) == false)
        return (false);
    return (true);
}
