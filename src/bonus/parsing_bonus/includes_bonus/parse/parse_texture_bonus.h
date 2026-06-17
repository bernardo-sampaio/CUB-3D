/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:32:19 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:04:11 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEXTURE_BONUS_H
# define PARSE_TEXTURE_BONUS_H

typedef struct s_texture_bonus
{
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
	char	*weap;
	char	*door[5];
}			t_texture_bonus;

#endif
