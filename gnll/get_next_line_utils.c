/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:02:16 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/25 12:17:04 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;
//	printf("asdf\n");

	i = 0;
	tab = malloc(count * size);
	printf("%zu %zu %lu %lu %p\n", count, size, sizeof(char), sizeof(int), tab);
	if (!tab)
		return (NULL);
	while (i < count * size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *) tab);
}

int	is_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*temp_stash(char *stash, char *temp, int j, int until_n)
{
	int	i;

	i = 0;
	while (i < until_n)
	{
		temp[j + i] = stash[i];
		i++;
	}
	return (temp);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	printf("calloc : %i\n", ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (res);
}
