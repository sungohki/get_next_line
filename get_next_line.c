/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/25 17:48:57y sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int		flag = -2;
	static int		cursor = 0;
	static char		temp[BUFFER_SIZE + 1];
	char			*result[2];

	if (flag == -2 || cursor >= flag)
		if (init(&flag, &cursor, temp, fd) == 0)
			return (NULL);
	result[0] = malloc_line(temp, cursor);
	while (result[0] != NULL && is_endofline(temp, cursor) == -1)
	{
		if (init(&flag, &cursor, temp, fd) == 0)
			break ;
		result[1] = result[0];
		result[0] = ft_strjoin(result[1], temp);
		free(result[1]);
	}
	if (flag == -1)
	{
		free(result[0]);
		return (NULL);
	}
	if (result[0] != NULL)
		cursor += line_len(temp, cursor);
	return (result[0]);
}
