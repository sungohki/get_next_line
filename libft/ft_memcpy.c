/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:24:35 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/10 00:23:31 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char			*dest;
	unsigned const char		*source;
	size_t					index;

	dest = (unsigned char *)dst;
	source = (unsigned const char *)src;
	index = 0;
	if (dst == src)
		return (dst);
	while (index < n)
	{
		dest[index] = source[index];
		index++;
	}
	return (dst);
}
