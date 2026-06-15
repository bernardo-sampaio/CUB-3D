/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:18:42 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 10:00:59 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char					*src_p;
	unsigned char						*dest_p;

	if (!dest || !src)
		return (dest);
	src_p = (const unsigned char *)src;
	dest_p = (unsigned char *)dest;
	if (dest_p == src_p)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			dest_p[n] = src_p[n];
		}
	}
	return (dest);
}
