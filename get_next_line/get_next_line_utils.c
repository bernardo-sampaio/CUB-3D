/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:35:59 by bsampaio          #+#    #+#             */
/*   Updated: 2025/10/30 10:56:30 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_txt(char *line, char *txt)
{
	size_t	i;

	i = 0;
	while (txt[i] && txt[i] != '\n')
	{
		line[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
	{
		line[i] = txt[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*s;

	if (!str)
		return (NULL);
	s = (char *)str;
	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return (&s[i]);
	else
		return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	dup = (char *) malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_new_str;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_new_str = (len_s1 + len_s2 + 1);
	new_str = (char *) malloc(sizeof(char) * (len_new_str));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strlcpy(new_str + len_s1, s2, len_s2 + 1);
	return (new_str);
}
