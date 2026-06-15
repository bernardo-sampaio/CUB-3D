/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:35:11 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 09:59:59 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = NULL;
	if (!content)
		return (new);
	new = malloc(sizeof(t_list));
	if (!new)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}
