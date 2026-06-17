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

int			count_map_lines_bonus(t_file *file);
bool		after_map_bonus(t_list *map);
bool		is_valid_char_bonus(t_map *map);
bool		check_map_bonus(t_file *file, t_map *map);

#endif
