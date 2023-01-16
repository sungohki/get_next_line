/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:48:15 by sungohki          #+#    #+#             */
/*   Updated: 2022/11/28 14:08:49 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;
	size_t				index;
	int					result;

	temp1 = (const unsigned char *)s1;
	temp2 = (const unsigned char *)s2;
	index = 0;
	result = 0;
	while (index < n)
	{
		result = temp1[index] - temp2[index];
		if (result != 0)
			return (result);
		index++;
	}
	return (0);
}
