/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:06:19 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/17 05:01:46 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	init(int *flag, int *cursor, char *temp, int fd)
{
	int		index;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	index = BUFFER_SIZE;
	while (index--)
		temp[index] = 0;
	*flag = read(fd, temp, BUFFER_SIZE);
	*cursor = 0;
	if (*flag == -1 || *flag == 0)
		return (0);
	else
		return (1);
}

int	is_endofline(char *temp, int cursor)
{
	int		index;

	index = cursor;
	while (index < BUFFER_SIZE)
	{
		if (temp[index] == 0)
			return (index);
		else if (temp[index] == '\n')
			return (index + 1);
		index++;
	}
	return (-1);
}

int	line_len(char *temp, int cursor)
{
	int		start;
	int		end;

	end = is_endofline(temp, cursor);
	if (end == -1)
		return (BUFFER_SIZE - cursor);
	start = cursor;
	return (end - start);
}

char	*malloc_line(char *temp, int cursor)
{
	char		*line;
	int			len;
	int			index;

	len = line_len(temp, cursor);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	index = 0;
	while (index + cursor < BUFFER_SIZE && index < len)
	{
		line[index] = temp[index + cursor];
		index++;
	}
	while (index <= len)
		line[index++] = 0;
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (s2 == 0)
		return (s1);
	if (!(s1) || !(s2))
		return (0);
	s1_len = 0;
	while (s1[s1_len] != 0 || s1[s1_len] != 0)
		s1_len++;
	s2_len = line_len(s2, 0);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	result[s1_len + s2_len] = 0;
	while (s2_len--)
		result[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		result[s1_len] = s1[s1_len];
	return (result);
}
