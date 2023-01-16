/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:47:03 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/19 18:32:16 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex_fd(unsigned int n, int fd, int isX)
{
	char	temp;

	if (isX == 1)
		temp = "0123456789ABCDEF"[n % 16];
	else if (isX == 0)
		temp = "0123456789abcdef"[n % 16];
	if (n / 16 > 0)
		ft_putnbr_hex_fd(n / 16, fd, isX);
	write(fd, &temp, 1);
}
