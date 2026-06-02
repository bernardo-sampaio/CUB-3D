/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:19:47 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 10:02:03 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(const char *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	mem_alloc(char **res, int index, int len)
{
	int	i;

	res[index] = ft_calloc(len, sizeof(char));
	if (!res[index])
	{
		i = 0;
		while (res[i])
			free(res[i++]);
		return (free(res), 0);
	}
	return (1);
}

static int	split_words(char **res, char const *s, char c)
{
	int	i;
	int	index;
	int	start;
	int	end;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (start < end)
		{
			if (!mem_alloc(res, index, end - start + 1))
				return (0);
			ft_strlcpy(res[index++], &s[start], end - start + 1);
		}
	}
	res[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(word_len(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (!split_words(res, s, c))
		return (NULL);
	return (res);
}
