/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:08:24 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 18:03:33 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

typedef struct s_tiles
{
	int		player;
	int		exit;
}			t_tiles;

typedef struct s_map
{
	t_tiles	tiles;
	char	**grid;
	int		width;
	int		height;
}			t_map;

bool		is_map_line(char *line);
bool		check_map(t_file *file, t_map *map);
int			count_map_lines(t_file *file);
bool		after_map(t_list *map);
void		copy_grid(t_map *map, int index, char *normalized_line);
bool		is_valid_char(t_map *map);

#endif
