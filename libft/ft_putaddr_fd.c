/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:40 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/21 22:09:10 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	addr_write(unsigned long n, int fd)
{
	char	temp;

	temp = "0123456789abcdef"[n % 16];
	if (n / 16 > 0)
		addr_write(n / 16, fd);
	write(fd, &temp, 1);
}

void	ft_putaddr_fd(void *ch, int fd)
{
	write(fd, "0x", 2);
	addr_write((unsigned long)ch, fd);
}
