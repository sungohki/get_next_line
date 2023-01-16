/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:06:19 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/16 18:01:52 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_endofline(char *temp)
{
	int		len;

	len = 0;
	while (len < BUFFER_SIZE)
	{
		if (temp[len] == 0)
			return (1);
		else if (temp[len] == '\n')
			return (2);
		len++;
	}
	return (0);
}

int	line_len(char *temp)
{
	int		len;

	len = 0;
	while (len < BUFFER_SIZE && temp[len] != '\n' && temp[len] != 0)
		len++;
	if (len < BUFFER_SIZE && temp[len] == '\n')
		len++;
	return (len);
}

char	*malloc_line(char *temp, int cursor)
{
	char		*line;
	int			len;
	int			index;

	len = line_len(&temp[cursor]);
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
	s2_len = line_len(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == 0)
		return (0);
	result[s1_len + s2_len] = 0;
	while (s2_len--)
		result[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		result[s1_len] = s1[s1_len];
	return (result);
}
