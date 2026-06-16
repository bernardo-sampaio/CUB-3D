/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:44 by ealbino           #+#    #+#             */
/*   Updated: 2025/12/02 07:29:15 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			*p;
	size_t					i;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
	return (NULL);
}
