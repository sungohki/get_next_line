/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/14 03:12:50 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int		flag = -2;
	static int		buffer = 0;
	static char		temp[BUFFER_SIZE];
	char			*result;

	if (flag == -2)
	{
		flag = read(fd, temp, BUFFER_SIZE);
		buffer = 0;
	}
	if (flag == -1 || flag == 0)
		return (NULL);
	if (has_null(temp) == 1)
		result = malloc_1(temp, &buffer, flag);
	else
		result = malloc_0(temp, flag);
	if (buffer++ >= flag || fd == 0)
		flag = -2;
	return (result);
}
