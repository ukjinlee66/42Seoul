/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:15:07 by youlee            #+#    #+#             */
/*   Updated: 2020/05/07 20:49:07 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			wild_check(long num, size_t *idx, t_form *f1, \
		va_list *ap)
{
	num = va_arg(*ap, int);
	if (num < 0)
		f1->flag[5] = (int)num;
	else
		f1->pre = (int)num;
	f1->exis[3] = true;
	f1->exis[2] = true;
	(*idx)++;
}

void				check_precision(t_type *t1, size_t *idx, t_form *f1, \
		va_list *ap)
{
	long num;

	num = 0;
	if (t1->format[*idx] == '.')
	{
		f1->exis[2] = true;
		(*idx)++;
		if (t1->format[*idx] == '*')
			return (wild_check(num, idx, f1, ap));
		while (t1->format[*idx] >= '0' && t1->format[*idx] <= '9')
		{
			num *= 10;
			if ((num + (long)(t1->format[*idx] - '0')) > 2147483647)
				t1->error = true;
			num += t1->format[*idx] - '0';
			(*idx)++;
		}
		f1->pre = (int)num;
	}
}
