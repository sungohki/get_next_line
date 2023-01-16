/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_us.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:48:26 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 16:47:44 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_us(unsigned int n)
{
	char			*result;
	unsigned int	temp;
	int				len;

	len = 1;
	temp = n;
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
