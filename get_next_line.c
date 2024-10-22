/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/22 12:08:05 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stash_in_line(char *stash, char *line, int *is_not_n)
{
	int	i;
	int	len_stash_tot;
	int	len_stash_n;

	i = 0;
	len_stash_tot = ft_strlen(stash);
	len_stash_n = ft_strlen_to_n(stash);
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line = ft_strjoin(line, stash, line, 0, i);
			*is_not_n = 0;
			return (line);
		}
		i++;
	}
	line = ft_strjoin(line, stash, line, 0, len_stash_tot);
	return (line);
}

char	*del_stash(char *stash)
{
	int	len_n;
	int len_tot;

	len_n = ft_strlen_to_n(stash);
	len_tot = ft_strlen(stash);
	if (len_n != len_tot)
		stash = ft_strjoin(NULL, stash, len_n, len_tot);
	else
		stash = NULL;
	return (stash);
}

char	*newline_cpy(char *line, char *buff, int *is_not_n)
{
	int	len_n;
	int	len_tot;

	len_n = ft_strlen_to_n(buff);
	len_tot = ft_strlen(buff);
	line = ft_strjoin(line, buff, line, 0, len_n);
	if (line[ft_strlen_to_n(line) - 1] == '\n')
		*is_not_n = 0;
	return (line);
}	

char	*rest_in_stash(char *buff, char *stash, char *line)
{
	int	length_tot;
	int	length_n;

	length_tot = ft_strlen(buff);
	length_n = ft_strlen_to_n(buff);
	if (length_n != length_tot)
		stash = ft_strjoin(stash, buff, line, length_n, length_tot);
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
	int			is_not_n;


	line = NULL;
	is_not_n = 1;
	if (stash)
		line = stash_in_line(stash, line, &is_not_n);
	printf("\033[0;32mline sans buff : %s\n", line);
	stash = del_stash(stash);
	isread = BUFFER_SIZE;
	while (isread == BUFFER_SIZE && is_not_n)
	{
		isread = read(fd, buff, BUFFER_SIZE);
		if (isread < 1)
			return (NULL);
		buff[isread] = '\0';
		printf("\033[0;31mbuff : %s\n", buff);
		line = newline_cpy(line, buff, &is_not_n);
		printf("\033[0;32mline : %s\n", line);
		stash = rest_in_stash(buff, stash, NULL);
		printf("\033[0;35mstash : %s\n", stash);
	}
	return (line);
}
