/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:01 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/25 17:00:11 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int fd1 = open("1char.txt", O_RDONLY);
	char *line;
//	int	fd2 = open("text.txt", O_RDONLY);

	for (int i = 0; i < 2; i++)
	{
		line = get_next_line(fd1);
//		printf("\033[0;32mline %d : %s\n", i + 1, line);
//		printf("\033[0;34m------------------------------------------------------\n");
		printf("\033[0;32mline %d : %s\n", i + 1, line);
		printf("\033[0;34m------------------------------------------------------\n");
		free(line);
	}
	return (0);
}
