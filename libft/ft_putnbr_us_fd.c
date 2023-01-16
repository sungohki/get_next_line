/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_us_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:21:35 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/21 20:27:25 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_us_fd(unsigned int n, int fd)
{
	char	temp;

	temp = n % 10 + '0';
	if (n / 10 > 0)
		ft_putnbr_us_fd(n / 10, fd);
	write(fd, &temp, 1);
}
