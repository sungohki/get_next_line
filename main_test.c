/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:49:40 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/31 20:09:42 by sungohki         ###   ########.fr       */
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
		int		size = 10;
		int		fd;
		int		num;

		fd = open("./test.txt", O_RDONLY);
		read(3, test10, 1);
		num = printf("%s", test10);
		printf("\ntest.txt has [%d] bytes, and read size is [%d].\n", num, size);
	}
	return (0);
}
