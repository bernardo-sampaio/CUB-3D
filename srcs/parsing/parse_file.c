/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:45:18 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/14 15:45:21 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_file/parse_file.h"

bool	is_dotcub(char *str)
{
	char	*cub;

    cub = ft_strrchr(str, '.');  
	if (ft_strncmp(cub, ".cub", ft_strlen(cub)) == 0)
		return (true);
	return (false);
}

