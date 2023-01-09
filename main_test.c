/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:49:40 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/09 16:05:10 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main ()
{
	if(1){
		char	test10[1024];
		int		size = 100;
		int		return_read;
		int		fd;
		int		num;

		fd = open("./test.txt", O_RDONLY);
		return_read = read(3, test10, size);
		num = printf("%s", test10);
		printf("\n## test.txt has [%d] bytes, and read size is [%d]. ##\n", num, size);
		printf("## read() returns : [%d]\n", return_read);

		char	test11[100];
		return_read = read(0, test11, 100);
		printf("## test11 : [%s] || buffer : [%d]", test11, return_read);
	}
	return (0);
}
