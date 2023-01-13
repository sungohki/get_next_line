/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:49:40 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/13 15:23:52y sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ex_func(void)
{
	static char		ex = 'a';

	printf("%c\n", ex++);
}

char	*gnl(int fd)
{
	static char		temp[BUFFER_SIZE];
	static int		flag = 0;
	static int		buffer = 0;
	int				len;
	int				sub;
	char			*result;

	len = buffer;
	if (flag++ == 0)
		read(fd, temp, BUFFER_SIZE);
		// flag = read(fd, temp, BUFFER_SIZE);
	// printf("// content : \n%s\n//\n", temp);	// check read correctly
	while (temp[len] != '\n' && temp[len] != 0)
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1 - buffer));
	if (result == 0)
		return (NULL);
	printf("// len : [%d]\n", buffer);
	sub = 0;
	while (buffer < len)
	{
		result[sub++] = temp[buffer++];
	}
	result[len] = temp[len];
	printf("// buffer : [%d]\n", buffer++);
	return (result);
}

int	main ()
{
	// // read func test
	// if(1){
	// 	char	test10[1024];
	// 	int		size = 100;
	// 	int		return_read;
	// 	int		fd;
	// 	int		num;

	// 	fd = open("./test.txt", O_RDONLY);
	// 	return_read = read(3, test10, size);
	// 	num = printf("%s", test10);
	// 	printf("\n## test.txt has [%d] bytes, and read size is [%d]. ##\n", num, size);
	// 	printf("## read() returns : [%d]\n", return_read);

	// 	char	test11[100];
	// 	return_read = read(0, test11, 100);
	// 	printf("## test11 : [%s] || buffer : [%d]", test11, return_read);
	// }

	// // static var test
	// if(1){
	// 	int		fd;
	// 	char	*test10;

	// 	// for(int i = 0; i < 5; i++)
	// 		// ex_func();
	// 	fd = open("./test.txt", O_RDONLY);
	// 	test10 = gnl(fd);
	// 	printf("// 1st gnl -> %s\n\n", test10);
	// 	free(test10);
	// 	test10 = gnl(fd);
	// 	printf("// 2nd gnl -> %s\n\n", test10);
	// }

	// get_next_line test
	 if(1){
		// char	test10[1024];
		char	*test11;
		int		fd;
		// int		rv;
		
		fd = open("./test.txt", O_RDONLY);
		test11 = get_next_line(0);
		printf("%s", test11);
	}
	return (0);
}
