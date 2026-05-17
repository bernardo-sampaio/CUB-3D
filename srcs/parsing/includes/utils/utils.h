/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:34:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/16 10:34:40 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <limits.h>

int     ft_strcmp(const char *s1, const char *s2);
bool	is_only_whitespace(char *str);
void	free_mat(char **mat);
void    free_texture(t_texture *texture_dir);
void	free_color(t_color *color);

#endif
