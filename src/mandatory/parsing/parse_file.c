/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:45:18 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/17 13:20:21 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d_parsing.h"

bool	validate_extension(char *filename, char *xtens)
{
	char	*after_dot;

	after_dot = ft_strrchr(filename, '.');
	if (ft_strcmp(after_dot, xtens) == 0)
		return (true);
	ft_putstr_fd("Error\n File [", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("] has not the extension required ", 2);
	ft_putendl_fd(xtens, 2);
	return (false);
}

static bool	open_file(const char *pathname, t_file *file)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		printf("Error:\n%s: %s\n", pathname, strerror(errno));
		exit(1);
	}
	file->fd = fd;
	return (true);
}

static bool	read_file(const char *pathname, t_file *file)
{
	t_list	*node;
	char	*line;

	if (open_file(pathname, file) == false)
		return (false);
	line = get_next_line(file->fd);
	while (line)
	{
		node = ft_lstnew(ft_strdup(line));
		if (node == NULL)
		{
			if (ft_lstsize(file->lines) > 0)
				ft_lstclear(&file->lines, free);
			return (close(file->fd), false);
		}
		ft_lstadd_back(&file->lines, node);
		free(line);
		line = get_next_line(file->fd);
	}
	file->line_count = ft_lstsize(file->lines);
	close(file->fd);
	return (true);
}

static bool	list_has_only_whitespaces(t_list *lst)
{
	while (lst)
	{
		if (is_only_whitespace((char *)lst->content) == false)
			return (false);
		lst = lst->next;
	}
	return (true);
}

bool	check_file(const char *pathname, t_file *file)
{
	if (read_file(pathname, file) == false)
		return (false);
	if (file->line_count == 0)
		return (error_msg("Empty file\n"), false);
	if (list_has_only_whitespaces(file->lines))
		return (error_msg("File contains only whitespace\n"), false);
	return (true);
}
