/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/15 20:56:01 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_eof(char *temp)
{
	int		len;

	len = 0;
	while (len < BUFFER_SIZE)
	{
		if (temp[len] == 0)
			return (1);
	}
	return (0);
}

int	line_len(char *temp, int cursor, int flag)
{
	int		len;

	len = cursor;
	while (len < flag && temp[len] != '\n' && temp[len] != 0)
	// 개행 또는 \0을 만날 때까지 길이 측정
		len++;
	if (len < flag && temp[len] == '\n')
	// 만약 마지막이 개행이었을 경우, \0자리를 위한 길이 1 추가
		len++;
	return (len);
}

char	*malloc_line(char *temp, int cursor, int flag)
{
	char		*line;
	int			len;
	int			index;

	len = line_len(temp, cursor, flag);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		line[index] = temp[index + cursor];
		index++;
	}
	line[len] = 0;
	return (line);
}

char	*function(char *temp, int len)
{
	int		flag;

	flag = read(fd, temp, BUFFER_SIZE);
	if (has_eof(temp) == 1)
		return (0);
	return (result);
}

char	*get_next_line(int fd)
{
	static int		flag = -2;
	static int		cursor = 0;
	char			*result;
	char			temp[BUFFER_SIZE];

	if (flag == -2)
	{
		flag = read(fd, temp, BUFFER_SIZE);
		cursor = 0;
	}
	if (flag == -1 || flag == 0)
	// 만약 read에 실패, 또는 읽을 정보가 없었을 경우에는 NULL
		return (NULL);
	result = malloc_line(temp, cursor, flag);
	cursor += line_len(temp, cursor, flag);
	if (cursor >= flag || fd == 0)
	{
		flag = -2;
	}
	// 만약 read로 불러온 길이를 cursor가 넘겼을 경우, 현 fd에 대해서 다시 read

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
