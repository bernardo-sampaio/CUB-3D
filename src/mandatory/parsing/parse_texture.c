/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:37:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/17 11:39:54 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

static bool	open_file(const char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		printf("Error:\n%s: %s\n", pathname, strerror(errno));
		return (false);
	}
	close(fd);
	return (true);
}

static bool	helper_validation(char **mat, char *chars, t_texture *texture_dir)
{
	char	*pathname;

	if (mat == NULL || chars == NULL)
		return (free(chars),
			helper("Memory allocation failed", mat), false);
	if (mat[0] && identify_direction(mat[0], chars))
	{
		if (mat[1][0] == '\n' || (mat[2]
				&& is_only_whitespace(mat[2]) == false))
			return (helper("Invalid pathname", mat), false);
		pathname = remove_breakline(mat[1]);
		if (validate_extension(pathname, ".xpm") == false)
		{
			free(pathname);
			if (mat)
				free_mat(mat);
			return (false);
		}
		if (open_file(pathname) == false)
			return (free(pathname), helper(NULL, mat), false);
		init_texture(mat[0], pathname, texture_dir);
		free(pathname);
	}
	return (true);
}

static bool	extract_path(t_file *file, t_texture *texture_dir)
{
	t_list	*head;
	char	**mat;
	char	*chars;

	chars = ft_calloc(6, sizeof(char));
	head = file->lines;
	while (head)
	{
		mat = ft_split((char *)head->content, ' ');
		if (helper_validation(mat, chars, texture_dir) == false)
			return (free(chars), false);
		free_mat(mat);
		head = head->next;
	}
	if ((ft_strlen(chars) != 4) || !(ft_strchr(chars, 'N')
			&& ft_strchr(chars, 'S') && ft_strchr(chars, 'W')
			&& ft_strchr(chars, 'E')))
	{
		if (ft_strlen(chars) > 4)
			return (free(chars),
				error_msg("Duplicate directions"), false);
		return (free(chars),
			error_msg("Miss direction in the file"), false);
	}
	return (free(chars), true);
}

bool	check_texture(t_file *file, t_texture *texture_dir)
{
	if (extract_path(file, texture_dir) == false)
		return (false);
	return (true);
}
