/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:39:09 by sungohki          #+#    #+#             */
/*   Updated: 2022/11/23 18:20:08 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_str;
	unsigned const char	*src_str;
	size_t				index;

	dst_str = (unsigned char *)dst;
	src_str = (unsigned const char *)src;
	if (dst == src)
		return (dst);
	index = 0;
	while (index < len)
	{
		if (dst < src)
			dst_str[index] = src_str[index];
		else
			dst_str[len - index - 1] = src_str[len - index - 1];
		index++;
	}
	return (dst);
}
