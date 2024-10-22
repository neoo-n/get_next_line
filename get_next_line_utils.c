/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:48 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/22 17:07:22 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* WHAT : malloc and place 0 in each
 * RETURN : new tab malloc				*/
void	*ft_calloc(size_t count, size_t size)
{
	int		*tab;
	size_t			i;

	i = 0;
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	while (i < count * size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *) tab);
}

// RETURN nb of char in s
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

// RETURN nb of char until '\n' in s (all char if no '\n')
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

/* WHAT : joining 2 str
 * HOW : 1) create new str (result)
 * 		 2) assign s1, then assign s2 from start to end
 * RETURN : str result									*/
char	*ft_strjoin(char *s1, char *s2, int start, int end)
{
	char	*result;
	int		i;
	int		j;
	int		len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	result = ft_calloc(len_s1 + end - start, sizeof(char));
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
	printf("\033[0;34mresult : %i\n", (result[i + j - 1] == '\n'));
	return (result);
}
