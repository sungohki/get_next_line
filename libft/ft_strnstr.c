/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:43:35 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/09 21:48:16 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;
	size_t		sub;

	index = 0;
	if (*needle == 0)
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack) + 1;
	while (haystack[index] && index < len)
	{
		if (haystack[index] == needle[0])
		{
			sub = 0;
			while (needle[sub] && needle[sub] == haystack[index + sub]
				&& haystack[index + sub] && index + sub < len)
				sub++;
			if (needle[sub] == 0)
				return (&((char *)haystack)[index]);
		}
		index++;
	}
	return (0);
}
