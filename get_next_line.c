/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/20 17:32:19 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stash_in_line(char *stash, char *line)
{
	int	i;
	int	len_stash;

	i = 0;
	len_stash = ft_strlen(stash);
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line = ft_strjoin(line, stash, 0, i);
			return (line);
		}
		i++;
	}
	line = ft_strjoin(line, stash, 0, len_stash);
	return (line);
}

char	*newline_cpy(char *buff, char *line)
{
	int	length_n;
	
	length_n = ft_strlen_to_n(buff);
	line = ft_strjoin(line, buff, 0, length_n);
	return (line);
}	

char	*rest_in_stash(char *buff, char *stash)
{
	int	length_tot;
	int	length_n;

	length_tot = ft_strlen(buff);
	length_n = ft_strlen_to_n(buff);
	if (length_n != length_tot)
		stash = ft_strjoin(stash, buff, length_n, length_tot);
	else
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	t_string	s_read;
	int			isread;

	s_read->line = NULL;
	if (s_read->stash)
		s_read->line = stash_in_line(s_read->stash, s_read->line);
	isread = BUFFER_SIZE;
	while (isread == BUFFER_SIZE)
	{
		isread = read(fd, s_read->buff, BUFFER_SIZE);
		if (!isread)
			return (NULL);
		s_read->buff[isread] = '\0';
		s_read->line = newline_cpy(s_read->buff, s_read->line);
		printf("line : %s\n", s_read->line);
	}
	return (s_read->line);
}
