/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:46:02 by sungohki          #+#    #+#             */
/*   Updated: 2023/01/15 21:51:21 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			index;
	int				result;

	index = 0;
	result = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (index < n)
	{
		result = us1[index] - us2[index];
		if (result != 0 || (!(us1[index]) || !(us2[index])))
			break ;
		index++;
	}
	return (result);
}
