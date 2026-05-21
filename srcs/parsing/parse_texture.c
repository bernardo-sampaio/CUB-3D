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

#include "core/cub3d.h"

bool	identify_direction(char *s)
{
	if (ft_strcmp(s, "NO") == 0 || ft_strcmp(s, "SO") == 0 || ft_strcmp(s,
			"WE") == 0 || ft_strcmp(s, "EA") == 0)
	{
		return (true);
	}
	return (false);
}

static char	*remove_breakline(char *pathname)
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

static void	init_texture(char *direction, char *pathname,
		t_texture *texture_dir)
{
	if (ft_strcmp(direction, "NO\n") == 0)
		texture_dir->north_text = ft_strdup(pathname);
	else if (ft_strcmp(direction, "SO") == 0)
		texture_dir->south_text = ft_strdup(pathname);
	else if (ft_strcmp(direction, "WE") == 0)
		texture_dir->west_text = ft_strdup(pathname);
	else if (ft_strcmp(direction, "EA") == 0)
		texture_dir->east_text = ft_strdup(pathname);
}

static bool	extract_path(t_file *file, t_texture *texture_dir)
{
	t_list	*head;
	char	**mat;
	char	*pathname;
	int		count;

	head = file->lines;
	count = 1;
	while (head)
	{
		mat = ft_split((char *)head->content, 32);
		if (mat[0] && identify_direction(mat[0]))
		{
			if (count > 4)
			{
				free_mat(mat);
				return (error_msg("Duplicate directions"), false);
			}
			if (mat[1][0] == '\n' || (mat[2]
					&& is_only_whitespace(mat[2]) == false))
			{
				free_mat(mat);
				return (error_msg("Invalid pathname"), false);
			}
			pathname = remove_breakline(mat[1]);
			if (validate_extension(pathname, ".xpm") == false)
			{
				free_mat(mat);
				free(pathname);
				return (error_msg("Invalid file extension. Expected .xpm\n"),
					false);
			}
			if (open_file(pathname) == false)
			{
				free_mat(mat);
				free(pathname);
				return (false);
			}
			init_texture(mat[0], pathname, texture_dir);
			free(pathname);
			count++;
		}
		free_mat(mat);
		head = head->next;
	}
	if (--count < 4)
		return (error_msg("Miss direction in the file\n"), false);
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
