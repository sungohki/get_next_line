/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:03 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/13 17:14:17 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*malloc_line(char *ch, int *buffer)
{
	char	*result;
	int		len;
	int		temp;

	len = *buffer;
	while (ch[len] != 0 && ch[len] != '\n')
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1 - *buffer));
	if (result == 0)
		return (NULL);
	temp = 0;
	while (*buffer < len)
		result[temp] = ch[*buffer++];
	result[len] = ch[len];
	*buffer++;
	return (result);
}
