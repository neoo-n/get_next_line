/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:47:07 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/23 17:35:17 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*read_line(char *s)
{
	char	buff[BUFFER_SIZE + 1];
	int		nb_read;
	int		i;

	nb_read = BUFFER_SIZE;
	i = 0;
	while (nb_read == BUFFER_SIZE)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read < 1)
			return (NULL);
		buff[nb_read] = '\0';
		stash[fd] = ft_strjoin(stash, buff, ft_strlen(buff));
		while (stash[fd][i])
		{
			if (stash[fd][i] == '\n')
				return (stash[fd]);
			i++;
		}
	}
	return (stash[fd]);
}

char	*cpy_line(char *stash)
{
	int		i;
	int		until_n;
	char	*temp;

	i = 0;
	until_n = 0;
	while (stash[until_n + 1] && stash[until_n] != '\n')
		until_n++;
	until_n++;
	temp = ft_calloc((until_n + 1) * sizeof(char));
	while (i <= until_n)
	{
		temp[i] = stash[i];
		i++;
	}
	return (temp);
}	

char	*get_next_line(int fd)
{
	static char *stash[3000];
	char		*line;

	if (!stash[fd])
	{
		stash[fd] = read_line(stash[fd]);
		if (!stash[fd])
		{
			free(stash[fd]);
			return (NULL);
		}
	}
	line = 
