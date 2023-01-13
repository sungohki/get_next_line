/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:03 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/13 22:26:16 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*malloc_line(char *ch, int *buffer, int flag)
{
	char	*result;
	int		len;
	int		temp;

	len = *buffer;
	while ((ch[len] != 0 && ch[len] != '\n') && len < flag)
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1 - *buffer));
	if (result == 0)
		return (NULL);
	temp = 0;
	while (*buffer < len)
		result[temp++] = ch[(*buffer)++];
	result[temp] = ch[*buffer];
	return (result);
}
