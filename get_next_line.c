/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:01 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/09 14:54:32 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*temp;
	char	*result;
	int		flag;

	flag = read(fd, temp, BUFFER_SIZE);
	if (flag == 0 || flag == 1)
		return (NULL);
	result = malloc_line(temp);
	return (result);
}
