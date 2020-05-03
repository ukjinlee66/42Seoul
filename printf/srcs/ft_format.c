/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 21:08:51 by youlee            #+#    #+#             */
/*   Updated: 2020/05/01 07:10:43 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_format(t_type *t1, size_t *index, t_form *f1, va_list *ap)
{
	if (t1->format[*index] == 'd' || t1->format[*index] == 'i')
		print_dec(f1, ap, t1);
	else if (t1->format[*index] == 'u' || t1->format[*index] == 'x' || \
			t1->format[*index] == 'X')
		print_unsigned(f1, ap, t1, index);
	else if (t1->format[*index] == 'c')
		printf_char(f1, ap, t1);
	else if (t1->format[*index] == 's')
		printf_str(f1, ap, t1);
	else if (t1->format[*index] == '%')
		printf_percent(f1, t1);
	else if (t1->format[*index] == 'p')
		printf_ptr(f1, ap, t1);
	else
	{
		write(1, &(t1->format[*index]), 1);
		t1->len++;
		return ;
	}
}
