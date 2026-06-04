/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:32:19 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 18:01:20 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEXTURE_H
# define PARSE_TEXTURE_H

typedef struct s_texture
{
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
}			t_texture;

bool		identify_direction(char *s, char *chars);
bool		check_texture(t_file *file, t_texture *texture_dir);
char		*remove_breakline(char *pathname);
void		init_texture(char *direction, char *pathname,
				t_texture *texture_dir);
void		helper(char *msg, char **mat);

#endif
