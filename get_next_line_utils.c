/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:06:19 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/14 03:07:57 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*malloc_1(char *ch, int *buffer, int flag)
{
	char	*result;
	int		len;
	int		temp;

	len = *buffer;
	while (len < flag && (ch[len] != 0 && ch[len] != '\n'))
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1 - *buffer));
	if (result == 0)
		return (NULL);
	temp = 0;
	while (*buffer < BUFFER_SIZE && *buffer < len)
		result[temp++] = ch[(*buffer)++];
	if (len == flag)
		result[temp] = 0;
	else
		result[temp] = '\n';
	return (result);
}

char	*malloc_0(char *ch, int flag)
{
	char	*result;
	int		len;
	int		temp;

	len = 0;
	while (len < flag && (ch[len] != 0 && ch[len] != '\n'))
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (NULL);
	temp = 0;
	result[(len--)] = 0;
	while (temp < len)
	{
		result[temp] = ch[temp];
		temp++;
	}
	return (result);
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
