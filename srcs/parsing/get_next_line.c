/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:28:06 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 11:06:07 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

static char	*ft_strjoin_secure(char *dst, const char *buf)
{
	char	*concat;
	size_t	i;
	size_t	j;

	if (!dst || !buf)
		return (NULL);
	concat = ft_calloc((ft_strlen(dst) + ft_strlen(buf) + 1), sizeof(char));
	if (!concat)
		return (NULL);
	i = -1;
	while (dst[++i])
		concat[i] = dst[i];
	j = 0;
	while (buf[j])
		concat[i++] = buf[j++];
	return (free(dst), concat);
}

static char	*get_next(char *buf)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	line = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!line)
		return (free(buf), NULL);
	j = 0;
	while (buf[++i])
		line[j++] = buf[i];
	return (free(buf), line);
}

static char	*get_first(char *buf)
{
	size_t	i;
	char	*first;

	if (!buf || !buf[0])
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	first = ft_calloc(i + 2, sizeof(char));
	if (!first)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		first[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		first[i] = '\n';
	return (first);
}

static char	*file_reader(int fd, char *dst)
{
	ssize_t	bytes_read;
	char	*buf;

	if (!dst)
	{
		dst = ft_calloc(1, 1);
		if (!dst)
			return (NULL);
	}
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(dst), free(buf), NULL);
		dst = ft_strjoin_secure(dst, buf);
		if (ft_strchr(dst, '\n'))
			break ;
	}
	return (free(buf), dst);
}

char	*get_next_line(int fd)
{
	static char	*dst;
	char		*first;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = file_reader(fd, dst);
	if (!dst)
		return (NULL);
	first = get_first(dst);
	dst = get_next(dst);
	return (first);
}
