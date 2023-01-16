/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:15:32 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/05 22:33:30 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		index;

	index = 0;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	while (s[start + index] && index < len)
		index++;
	result = (char *)malloc(sizeof(char) * (index + 1));
	if (result == 0)
		return (0);
	result[index] = 0;
	while (index--)
		result[index] = s[start + index];
	return (result);
}
