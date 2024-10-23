/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/23 16:46:41 by dvauthey         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

/*
WHAT : read file until next '\n' or the end
		put it in stash[fd]
RETURN : stash[fd]
*/

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
		stash = ft_strjoin(stash, buff, ft_strlen(buff));
		while (stash[i])
		{
			if (stash[i] == '\n')
				is_n = 0;
			i++;
		}
	}
	return (stash);
}

/*
WHAT : take the stash[fd] and fill line until '\n' or the end
RETURN : line
*/

static char	*stash_in_line(char *stash, char *line)
{
	int	i;
	int	len_stash_tot;

	i = 0;
	len_stash_tot = ft_strlen(stash);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line = ft_strjoin(line, stash, i + 1);
			printf("liii iii iiii iiii iiine : %s\n", line);
			return (line);
		}
		i++;
	}
	line = ft_strjoin(line, stash, len_stash_tot);
	return (line);
}

/*
WHAT : delete what's in stash[fd] until '\n' or the end
RETURN : stash[fd]
*/

static char	*del_stash(char *stash)
{
	int		i;

	i = 0;
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
	{
		i++;
		stash = str_cut(stash, i, ft_strlen(stash) - i);
	}
	else
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

/*
WHAT : read a file and return next line
RETURN : line
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (stash)
	{
		line = stash_in_line(stash, line);
		stash = del_stash(stash);
	}
	printf("\033[0;35mline : %s\n", line);
	if (!stash)
	{
		stash = read_line(fd, stash);
		printf("\033[0;31mstash[%d] : %s\n", fd, stash);
		if (!stash)
		{
			free(stash);
			return (NULL);
		}
		line = stash_in_line(stash, line);
		printf("\033[0;35mline : %s\n", line);
		stash = del_stash(stash);
	}
		printf("\033[0;32mstash[%d] : %s\n", fd, stash);
	return (line);
}
