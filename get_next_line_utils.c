/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:06:19 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/15 21:01:48 by sungohki         ###   ########.fr       */
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

int	has_null(char *temp)
{
	int		len;

	len = 0;
	while (len < BUFFER_SIZE)
	{
		if (temp[len++] == 0)
			return (1);
	}
	return (0);
}
