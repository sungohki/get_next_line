/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:19:35 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/17 01:51:07 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	ft_strlen(char *ch)
{
	int		len;

	len = 0;
	while (ch[len] != 0)
		len++;
	return (len);
}

int	main(void)
{
	if (1)
	{
		int		fd;
		char	*test;
		char	test10[BUFFER_SIZE + 1];
		int		trytime;

		fd = open("test.txt", O_RDONLY);
		test = "hi";
		// int	size = read(fd, test10, BUFFER_SIZE);
		trytime = 1;
		printf("##          BUFFER_SIZE == %d        ##\n\n", BUFFER_SIZE);
		// while (size != 0 && size != -1)
		// {
		// 	printf("## %d try! read : [ %2d ]\n-> [%s]\n", trytime++, ft_strlen(test10), test10);
		// 	printf("## buffer[%d] == [%c] == (char)%d\n\n", size, test10[size], (int)test10[size]);
		// 	size = read(fd, test10, BUFFER_SIZE);
		// }
		
		while (test != NULL)
		{
			test = get_next_line(0);
			printf("## try %d -> gnl test : [%s]\n", trytime++, test);
		}
	}
	printf("##           the end          ##\n");
	return (0);
}
