/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:38 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 22:14:25 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char				*a;
	unsigned char				*b;
	size_t						i;

	if (!s1 && !s2)
		return (0);
	if (s1 && !s2)
		return (1);
	if (!s1 && s2)
		return (-1);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (a[i] != b[i])
			return (a[i] - b[i]);
	return (0);
}
