/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:52:13 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 16:57:02 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	t_list *temp2;

	if (lst && *lst)
	{
		temp = (*lst);
		while (temp->next != NULL)
		{
			temp2 = temp->next;
			ft_lstdelone(temp, del);
			temp = temp2;
		}
		ft_lstdelone(temp, del);
		*lst = NULL;
	}
}
