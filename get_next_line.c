/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/22 17:07:25 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
	int		i;
	int		read_size;
	int		is_n;

	i = 0;
	read_size = BUFFER_SIZE;
	is_n = 1;
	while (is_n && read_size == BUFFER_SIZE)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 1)
			return (NULL);
		buff[read_size] = '\0';
		printf("\033[0;32mbuff : %s\n", buff);
		stash = ft_strjoin(stash, buff, 0, ft_strlen(buff));
		while (stash[i])
		{
			if (stash[i] == '\n')
				is_n = 0;
			i++;
		}
	}
	return (stash);
}

static char	*stash_in_line(char *stash, char *line)
{
	int	i;
	int	len_stash_tot;

	i = 0;
	len_stash_tot = ft_strlen(stash);
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line = ft_strjoin(line, stash, 0, i + 1);
			return (line);
		}
		i++;
	}
	line = ft_strjoin(line, stash, 0, len_stash_tot);
	return (line);
}

static char	*del_stash(char *stash)
{
	int	len_n;
	int len_tot;

	len_n = ft_strlen_to_n(stash);
	len_tot = ft_strlen(stash);
	if (len_n != len_tot)
		stash = ft_strjoin(NULL, stash, len_n, len_tot);
	else
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;


	line = NULL;
	printf("\033[0;33mstash : %s\n", stash);
	if (stash)
	{
		line = stash_in_line(stash, line);
		stash = del_stash(stash);
	}
	if (!stash)
	{
		stash = read_line(fd, stash);
		printf("\033[0;31mstash : %s\n", stash);
		line = ft_strjoin(line, stash, 0, ft_strlen_to_n(stash));
		stash = del_stash(stash);
	}
	return (line);
}
