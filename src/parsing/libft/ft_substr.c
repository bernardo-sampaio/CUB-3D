/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:22:18 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 10:04:32 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		sub_len;
	char		*new;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		new = ft_calloc(1, sizeof(char));
		if (!new)
			return (NULL);
		return (new);
	}
	sub_len = ft_strlen(s) - start;
	if (sub_len > len)
		sub_len = len;
	new = ft_calloc(sub_len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, sub_len + 1);
	return (new);
}
