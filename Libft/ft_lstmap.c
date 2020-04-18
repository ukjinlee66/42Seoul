/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:25:15 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:03:54 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ans;
	t_list *temp;
	t_list *new;

	temp = lst;
	if (!lst)
		return (NULL);
	ans = ft_lstnew(f(temp->content));
	temp = temp->next;
	while (temp)
	{
		if (!(new = ft_lstnew(f(temp->content))))
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		ft_lstadd_back(&ans, new);
		temp = temp->next;
	}
	return (ans);
}
