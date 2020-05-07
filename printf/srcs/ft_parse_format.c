/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:30:43 by youlee            #+#    #+#             */
/*   Updated: 2020/05/07 20:04:44 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_format(t_type *t1, va_list *ap, t_form *f1)
{
	size_t	index;

	index = 0;
	while (t1->format[index])
	{
		if (t1->format[index] == '%')
		{
			index++;
			check_flag(t1, &index, f1);
			check_width(t1, ap, &index, f1);
			check_precision(t1, &index, f1, ap);
			check_format(t1, &index, f1, ap);
			init_func(t1, f1);
		}
		else
		{
			write(1, &(t1->format[index]), 1);
			t1->len++;
		}
		index++;
	}
}
