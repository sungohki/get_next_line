/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:54:53 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/10 00:42:42 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_not_set(char const s1, char const *set)
{
	while (*set)
		if (s1 == *(set++))
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		start;
	size_t		end;
	size_t		len;

	if (s1 == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_not_set(s1[start], set) == 0 && s1[start])
		start++;
	while (is_not_set(s1[end], set) == 0 && end)
		end--;
	len = end - start + 1;
	if (s1[start] == 0 || *s1 == 0)
		len = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	result[len] = 0;
	while (len--)
		result[len] = s1[end--];
	return (result);
}
