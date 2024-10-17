/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:48 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/17 17:13:07 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_toprint(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int start, int end)
{
	char	*result;
	int		i;
	int		j;

	i = ft_strlen_toprint(s1);
	j = end - start;
	result = malloc(sizeof(char) * (i + j));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (j - 1 > 0)
	{
		result[i + j - 1] = s2[start + j - 1];
		j--;
	}
	return (result);
}
