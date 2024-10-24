/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:02:16 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/24 17:15:09 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size, int *calloc_err)
{
	char		*tab;
	size_t	i;
//	printf("asdf\n");

	i = 0;
	tab = malloc(count * size);
	//printf("%zu %zu %lu %lu %p\n", count, size, sizeof(char), sizeof(int), tab);
	if (!tab)
	{
		*calloc_err = 1;
		return (NULL);
	}
	while (i < count * size)
	{
//		printf("heeeeeeeeelp\n");
		tab[i] = 0;
//		printf("tab[i] : %i\n", tab[i]);
		i++;
	}
//	printf("tab[1] = %i, tab[2] = %i\n", tab[0], tab[1]);
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
	int		calloc_err;

	i = 0;
	j = 0;
	calloc_err = 0;
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char), &calloc_err);
	if (!res && calloc_err)
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
	res[i + j] = '\0';
//		printf("res : %s\n", res);
	return (res);

}
