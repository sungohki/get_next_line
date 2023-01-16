/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:16:30 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/05 20:14:36 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long n, int fd)
{
	char	temp;

	temp = n % 10 + '0';
	if (n / 10 > 0)
		ft_putnbr(n / 10, fd);
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_putnbr((long)n, fd);
	else
	{
		write(fd, "-", 1);
		ft_putnbr(-(long)n, fd);
	}
}
