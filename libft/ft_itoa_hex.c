/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:48:29 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 16:47:55 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_hex(unsigned int n, int isX)
{
	char			*result;
	unsigned int	temp;
	int				len;

	len = 1;
	temp = (long) n;
	while (temp / 16 > 0)
	{
		len++;
		temp = temp / 16;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	result[len] = 0;
	while (len--)
	{
		if (isX == 0)
			result[len] = "0123456789abcdef"[n % 16];
		else
			result[len] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
	}
	return (result);
}
