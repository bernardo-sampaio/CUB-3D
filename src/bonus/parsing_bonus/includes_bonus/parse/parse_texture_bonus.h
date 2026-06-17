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

typedef struct s_texture
{
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
	char	*weap;
	char	*door[5];
}			t_texture;

bool		identify_direction(char *s, char *chars);
bool		check_texture(t_file *file, t_texture *texture_dir);
char		*remove_breakline(char *pathname);
void		init_texture(char *direction, char *pathname,
				t_texture *texture_dir);
void		helper(char *msg, char **mat);

#endif
