/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:01 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/25 14:27:08 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
//	int fd1 = open("1char.txt", O_RDONLY);
//	char *line;
	int	fd2 = open("text.txt", O_RDONLY);

	for (int i = 0; i < 9; i++)
	{
//		line = get_next_line(fd1);
//		printf("\033[0;32mline %d : %s\n", i + 1, line);
//		printf("\033[0;34m------------------------------------------------------\n");
//		free(line);
		printf("\033[0;32mline %d : %s\n", i + 1, get_next_line(fd2));
		printf("\033[0;34m------------------------------------------------------\n");
	}
	return (0);
}
