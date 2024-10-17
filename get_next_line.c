/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/17 17:13:04 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	**stash;
	char		*line;
	int			isread;
	int			count;
	char		buff[BUFFER_SIZE + 1];

	isread = 1;
	count = 0;
	line = NULL;
	if (stash)
	{
		line = ft_strjoin(line, stash, 0, ft_strlen(stash));
		line = ft_strjoin("\0", line, ft_strlen(line), ft_strlen(line) + 1);
	}
	while (isread)
	{
		isread = read(fd, buff, BUFFER_SIZE);
		if (!isread && !count)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buff, 0, ft_strlen_toprint(buff));
		if (ft_strlen_toprint(buff) != ft_strlen(buff))
			stash = ft_strjoin(stash, buff, ft_strlen_toprint(buff), ft_strlen(buff));
	}
	return (line);
}
