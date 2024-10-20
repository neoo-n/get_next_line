/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:38:56 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/20 17:23:38 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_string
{
	static char	*stash;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
}	t_string;

char    *newline_cpy(char *buff, char *line);
char    *rest_in_stash(char *buff, char *stash);
char    *get_next_line(int fd);
int		ft_strlen(char *s);
int 	ft_strlen_to_n(char *s);
char    *ft_strjoin(char *s1, char *s2, int start, int end);

#endif
