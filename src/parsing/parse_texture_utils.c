/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:02:34 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/27 11:02:35 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

bool	identify_direction(char *s)
{
	if (ft_strcmp(s, "NO") == 0 || ft_strcmp(s, "SO") == 0 || ft_strcmp(s,
			"WE") == 0 || ft_strcmp(s, "EA") == 0)
	{
		return (true);
	}
	return (false);
}

char	*remove_breakline(char *pathname)
{
	char	*new;
	int		i;

	new = ft_calloc(ft_strlen(pathname), sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (pathname[i] && pathname[i] != '\n')
	{
		new[i] = pathname[i];
		i++;
	}
	return (new);
}

void	init_texture(char *direction, char *pathname, t_texture *texture_dir)
{
	if (ft_strcmp(direction, "NO") == 0)
		texture_dir->north_text = ft_strdup(pathname);
	else if (ft_strcmp(direction, "SO") == 0)
		texture_dir->south_text = ft_strdup(pathname);
	else if (ft_strcmp(direction, "WE") == 0)
		texture_dir->west_text = ft_strdup(pathname);
	else if (ft_strcmp(direction, "EA") == 0)
		texture_dir->east_text = ft_strdup(pathname);
}

void	helper(char *msg, char **mat)
{
	free_mat(mat);
	if (msg)
		error_msg(msg);
}
