/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/16 17:54:53 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int		flag = -2;
	static int		cursor = 0;
	static char		temp[BUFFER_SIZE];
	char			*result;
	char			*sub;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (flag == -2)
	{
		flag = read(fd, temp, BUFFER_SIZE);
		cursor = 0;
	}
	if (flag == -1 || flag == 0)
		return (NULL);
	result = malloc_line(temp, cursor);
	while (is_endofline(temp) == 0)
	{
		flag = read(fd, temp, BUFFER_SIZE);
		if (flag == -1 || flag == 0)
			break ;
		sub = result;
		result = ft_strjoin(sub, temp);
		free(sub);
	}
	cursor += line_len(&temp[cursor]);
	if (cursor + 1 >= flag || fd == 0)
		flag = -2;
	return (result);
}

// char	*get_next_line(int fd)
// {
// 	static int		flag = -2;
// 	static int		cursor = 0;
// 	char			*result;
// 	char			temp[BUFFER_SIZE];

// 	if (flag == -2)
// 	{
// 		flag = read(fd, temp, BUFFER_SIZE);
// 		cursor = 0;
// 	}
// 	if (flag == -1 || flag == 0)
// 	// 만약 read에 실패, 또는 읽을 정보가 없었을 경우에는 NULL
// 		return (NULL);
// 	result = malloc_line(temp, cursor, flag);
// 	cursor += line_len(temp, cursor, flag);
// 	if (cursor >= flag || fd == 0)
// 	{
// 		flag = -2;
// 	}
// 	// 만약 read로 불러온 길이를 cursor가 넘겼을 경우, 현 fd에 대해서 다시 read

// 	return (result);
// }
