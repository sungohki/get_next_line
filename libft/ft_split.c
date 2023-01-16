/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:18:40 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/09 21:07:34 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	count;

	if (s == 0)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*seperate_word(char const *s, char c)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (*s && *s == c)
		s++;
	while (*(s + len) && *(s + len) != c)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**ft_split_free(char **result, size_t index)
{
	while (index--)
		free(result[index]);
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		count;
	size_t		index;

	if (s == 0)
		return (0);
	count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == 0)
		return (0);
	result[count] = 0;
	index = 0;
	while (*s && index < count)
	{
		result[index] = seperate_word(s, c);
		if (result[index] == 0)
			return (ft_split_free(result, index));
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		index++;
	}
	return (result);
}
