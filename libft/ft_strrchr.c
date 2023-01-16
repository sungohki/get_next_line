/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:14:59 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/10 00:42:37 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	convert_c;

	result = (char *)s;
	convert_c = (char) c;
	while (*result)
		result++;
	while (s != result)
	{
		if (*result == convert_c)
			return (result);
		result--;
	}
	if (*result == convert_c)
		return (result);
	else
		return (0);
}
