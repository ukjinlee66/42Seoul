/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:40:26 by youlee            #+#    #+#             */
/*   Updated: 2020/04/03 19:55:14 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = (*lst);
	if (!*lst || !lst)
		*lst = new;
	else
	{
		while ((temp->next) != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
