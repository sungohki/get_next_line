/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/17 02:12:07 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static int		flag = -2;
	static int		cursor = 0;
	static char		temp[BUFFER_SIZE + 1];
	char			*result;
	char			*sub;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (flag == -2 || cursor >= flag || fd == 0)
	{
		flag = read(fd, temp, BUFFER_SIZE);
		cursor = 0;
	}
	if (flag == -1 || flag == 0)
		return (NULL);
	result = malloc_line(temp, cursor);
	while (is_endofline(temp, cursor) == 0)
	{
		ft_bzero(temp, BUFFER_SIZE);
		flag = read(fd, temp, BUFFER_SIZE);
		cursor = 0;
		if (flag == -1 || flag == 0)
			break ;
		sub = result;
		result = ft_strjoin(sub, temp);
		free(sub);
	}	
	if (flag == -1)
	{
		free(result);
		return (NULL);
	}
	cursor += line_len(temp, cursor);
	return (result);
}
