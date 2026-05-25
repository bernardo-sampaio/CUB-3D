/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:33:28 by bsampaio          #+#    #+#             */
/*   Updated: 2025/11/27 12:54:52 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_get_line(char *txt)
{
	char		*line;
	size_t		i;

	if (!txt)
		return (NULL);
	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	if (txt[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	return (ft_copy_txt(line, txt));
}

static	char	*ft_get_remainder(char *txt)
{
	size_t		i;
	char		*rest;

	if (!txt)
		return (NULL);
	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	if (txt[i] == '\0')
	{
		free(txt);
		return (NULL);
	}
	rest = ft_strdup(txt + i + 1);
	free(txt);
	if (rest && rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

static	char	*ft_verify_txt(char *txt, char *buffer)
{
	char	*temp;

	if (!txt)
		txt = ft_strdup(buffer);
	else
	{
		temp = txt;
		txt = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (txt);
}

static char	*ft_handle_eof(char **txt, char *buffer, ssize_t bytes_read)
{
	char	*line;

	free(buffer);
	if (bytes_read == 0 && *txt && **txt)
	{
		line = ft_get_line(*txt);
		*txt = ft_get_remainder(*txt);
		return (line);
	}
	free(*txt);
	*txt = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*txt;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(txt, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_handle_eof(&txt, buffer, bytes_read));
		buffer[bytes_read] = '\0';
		txt = ft_verify_txt(txt, buffer);
	}
	free(buffer);
	line = ft_get_line(txt);
	txt = ft_get_remainder(txt);
	return (line);
}
