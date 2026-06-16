/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:53:39 by ealbino           #+#    #+#             */
/*   Updated: 2026/06/16 10:03:32 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_BONUS_H
# define PARSE_FILE_BONUS_H
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_file
{
	t_list	*lines;
	int		fd;
	int		line_count;
}			t_file;

bool		validate_extension(char *filename, char *xtens);
bool		check_file(const char *pathname, t_file *file);

#endif
