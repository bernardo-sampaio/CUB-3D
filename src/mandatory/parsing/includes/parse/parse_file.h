/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:53:39 by ealbino           #+#    #+#             */
/*   Updated: 2026/05/19 18:02:36 by ealbino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_H
# define PARSE_FILE_H
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
