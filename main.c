/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:06:17 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/18 16:41:50 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	printf("first line : %s\n", get_next_line(fd));
	printf("second line : %s\n", get_next_line(fd));
	printf("third line : %s\n", get_next_line(fd));
	return (0);
}
