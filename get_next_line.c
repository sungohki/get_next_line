/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/13 17:13:38 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		temp[BUFFER_SIZE];
	static int		flag = -2;
	static int		buffer = 0;
	char			*result;

	if (flag == -2)
		flag = read(fd, temp, BUFFER_SIZE);
	if (flag == 0 || flag == 1)
		return (NULL);
	result = malloc_line(temp, &buffer);
	return (result);
}
