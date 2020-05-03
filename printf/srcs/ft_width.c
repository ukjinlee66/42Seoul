/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 18:26:29 by youlee            #+#    #+#             */
/*   Updated: 2020/04/26 01:50:17 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_width(t_type *t1, size_t *idx, t_form *f1)
{
	long	num;

	num = 0;
	while (t1->format[*idx] >= '0' && t1->format[*idx] <= '9')
	{
		if (f1->exis[1] == false)
			f1->exis[1] = true;
		num *= 10;
		if ((num + (long)(t1->format[*idx] - '0')) > 2147483647)
		{
			t1->error = true;
			return ;
		}
		num += (t1->format[*idx] - '0');
		(*idx)++;
	}
	f1->width = (int)num;
}
