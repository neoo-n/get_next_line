/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/21 13:57:27 by dvauthey         ###   ########.fr       */
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

char	*newline_cpy(char *line, char *buff)
{
	int	len_n;
	int	len_tot;

	len_n = ft_strlen_to_n(buff);
	len_tot = ft_strlen(buff);
	line = ft_strjoin(line, buff, 0, len_n);
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
	char		*line;
	static char	*stash;
	char		buff[BUFFER_SIZE + 1];
	int			isread;


	line = NULL;
	if (stash)
		line = stash_in_line(stash, line);
	isread = BUFFER_SIZE;
	while (isread == BUFFER_SIZE)
	{
		if (line && line[ft_strlen_to_n(line) - 1] == '\n')
			return (line);
		isread = read(fd, buff, BUFFER_SIZE);
		if (isread < 1)
			return (NULL);
		buff[isread] = '\0';
		printf("buff : %s\n", buff);
		line = newline_cpy(line, buff);
		printf("line : %s\n", line);
		stash = rest_in_stash(buff, stash);
		printf("stash : %s\n", stash);
	}
	return (line);
}
