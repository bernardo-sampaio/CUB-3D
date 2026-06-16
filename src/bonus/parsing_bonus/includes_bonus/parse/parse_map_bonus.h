/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:08:24 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:03:52 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_BONUS_H
# define PARSE_MAP_BONUS_H

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
