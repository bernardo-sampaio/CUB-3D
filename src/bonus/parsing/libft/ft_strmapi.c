/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:21:03 by ealbino           #+#    #+#             */
/*   Updated: 2025/12/02 07:34:08 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		index;

	if (!s || !f)
		return (NULL);
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new)
		return (NULL);
	index = -1;
	while (s[++index])
		new[index] = f(index, s[index]);
	new[index] = '\0';
	return (new);
}
