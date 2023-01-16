/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:10:50 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/10 00:40:02 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		dstsize = src_len + 1;
	if (dst == src || dstsize == 0)
		return (src_len);
	dst[--dstsize] = 0;
	while (dstsize--)
		dst[dstsize] = src[dstsize];
	return (src_len);
}
