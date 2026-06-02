/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:37:38 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 18:12:33 by ealbino          ###   ########.fr       */
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

static bool	helper_validation(char **mat, int *count, t_texture *texture_dir)
{
	char	*pathname;

	if (mat[0] && identify_direction(mat[0]))
	{
		if (*count > 4)
			return (helper("Duplicate directions", mat), false);
		if (mat[1][0] == '\n' || (mat[2]
				&& is_only_whitespace(mat[2]) == false))
			return (helper("Invalid pathname", mat), false);
		pathname = remove_breakline(mat[1]);
		if (validate_extension(pathname, ".xpm") == false)
		{
			free(pathname);
			return (helper("Invalid file extension. Expected .xpm", mat),
				false);
		}
		if (open_file(pathname) == false)
			return (free(pathname), helper(NULL, mat), false);
		init_texture(mat[0], pathname, texture_dir);
		free(pathname);
		(*count)++;
	}
	return (true);
}

static bool	extract_path(t_file *file, t_texture *texture_dir)
{
	t_list	*head;
	char	**mat;
	int		count;

	head = file->lines;
	count = 1;
	while (head)
	{
		mat = ft_split((char *)head->content, 32);
		if (mat == NULL)
			return (helper("Memory allocation failed", mat), false);
		if (helper_validation(mat, &count, texture_dir) == false)
			return (false);
		free_mat(mat);
		head = head->next;
	}
	if (--count < 4)
		return (error_msg("Miss direction in the file"), false);
	return (true);
}

bool	check_texture(t_file *file, t_texture *texture_dir)
{
	if (extract_path(file, texture_dir) == false)
	{
		ft_lstclear(&file->lines, free);
		free_texture(texture_dir);
		return (false);
	}
	return (true);
}
