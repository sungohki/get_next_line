/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:52:03 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/09 14:54:27 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	malloc_line(char *ch)
{
	int		len;
	char	*result;

	len = 0;
	while (ch[len] == 0)
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (NULL);
	result[len] = 0;
	while (len-- > 0)
		result[len] = ch[len];
	return (result);
}
