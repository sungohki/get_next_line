/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:30:43 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/10 00:15:55 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;
	void	*temp;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	result = 0;
	while (lst != 0)
	{
		temp = f(lst->content);
		if (temp == 0)
			break ;
		new = ft_lstnew(temp);
		if (new == 0)
		{
			del(temp);
			break ;
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	if (lst != 0)
		ft_lstclear(&result, del);
	return (result);
}
