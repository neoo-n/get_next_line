/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/18 11:55:29 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*open_files_buff(int fd, char *buff)
{
	int		isread;

	isread = read(fd, buff, BUFFER_SIZE);
	if (!isread)
		return (NULL);
	buff[BUFFER_SIZE] = '\0';
	return (buff);
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
	static char	**stash;
	char		*line;
	char		buff[BUFFER_SIZE];

	line = NULL;
	if (stash)
		line = ft_strjoin(line, stash, 0, ft_strlen(stash));
	while (isread)
	{
		buff = open_files_buff(fd, buff);
		if (!buff)
			return (NULL);
		line = newline_cpy(buff, line);
		stash = rest_in_stash(buff, stash);
	}
	return (line);
}
