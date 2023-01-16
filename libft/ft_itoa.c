/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:22:47 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/05 23:01:16 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_positive(long n, int is_minus)
{
	char	*result;
	long	temp;
	int		len;

	len = 1 + is_minus;
	temp = (long) n;
	while (temp / 10 > 0)
	{
		len++;
		temp = temp / 10;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	result[len] = 0;
	while (len--)
	{
		result[len] = n % 10 + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;

	if (n >= 0)
		result = ft_itoa_positive((long)n, 0);
	else
	{
		result = ft_itoa_positive(-(long)n, 1);
		if (result && result[0] == '0')
			result[0] = '-';
	}
	return (result);
}
