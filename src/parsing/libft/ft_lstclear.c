/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:34:48 by ealbino           #+#    #+#             */
/*   Updated: 2025/11/30 09:59:04 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = aux;
	}
	*lst = NULL;
}
