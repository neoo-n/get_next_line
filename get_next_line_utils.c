/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:48 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/21 13:57:29 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen_to_n(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
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
	int		len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	result = malloc(sizeof(char) * (len_s1 + end - start));
	if (!result)
		return (NULL);
	while (i < len_s1) 
	{
		result[i] = s1[i];
		i++;
	}
	while (j < end - start)
	{
		result[i + j] = s2[start + j];
		j++;
	}
	return (result);
}
