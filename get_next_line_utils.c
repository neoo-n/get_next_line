/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:48 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/23 16:46:44 by dvauthey         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

/* WHAT : malloc and place 0 in each
 * RETURN : new tab malloc				*/
void	*ft_calloc(size_t count)
{
	int		*tab;
	size_t			i;

	i = 0;
	tab = malloc(count);
	if (tab == NULL)
		return (NULL);
	while (i < count)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
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

char	*str_cut(char *s, int start, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_calloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}

/* WHAT : joining 2 str
 * HOW : 1) create new str (result)
 * 		 2) assign s1, then assign s2 from start to end
 * RETURN : str result									*/
char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*res;
	int		i;
	int		j;
	int		len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	res = (char *) ft_calloc((len_s1 + len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	printf("stashh shshsh sshshshshshshshshsh %s\n", s2);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (j < len)
	{
		res[i + j] = s2[j];
		j++;
	}
	return (res);
}
