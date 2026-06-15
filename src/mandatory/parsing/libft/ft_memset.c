/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:18:54 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 10:01:09 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char				*ptr;
	size_t						i;

	if (!s)
		return (s);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char) c;
	return (s);
}
