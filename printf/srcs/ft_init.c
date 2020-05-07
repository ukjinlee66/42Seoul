/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:27:07 by youlee            #+#    #+#             */
/*   Updated: 2020/05/06 15:54:45 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_func(t_type *tt, t_form *ff)
{
	size_t	index;

	index = 0;
	tt->ans = 0;
	while (index < 6)
	{
		if (index < 4)
			ff->exis[index] = false;
		ff->flag[index] = 0;
		index++;
	}
	ff->width = 0;
	ff->pre = 0;
	ff->neg = false;
	tt->size = 0;
}
