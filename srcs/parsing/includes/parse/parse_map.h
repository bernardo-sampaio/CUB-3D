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
	int	player;
	int	exit;
}	t_tiles;

typedef struct s_map
{
	t_tiles		tiles;
	char	**grid;
	int		width;
	int		height;
}	t_map;

bool	check_map(t_file *file, t_map *map);

#endif
