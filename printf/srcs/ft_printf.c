/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:12:54 by youlee            #+#    #+#             */
/*   Updated: 2020/05/07 18:22:08 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_typ(t_type *tt, t_form *ff)
{
	size_t		index;

	index = 0;
	tt->format = 0;
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
	tt->error = false;
	tt->size = 0;
	tt->len = 0;
	ff->neg = false;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_type		t1;
	t_form		f1;

	va_start(ap, format);
	init_typ(&t1, &f1);
	t1.format = format;
	parse_format(&t1, &ap, &f1);
	if (t1.error)
		return (-1);
	va_end(ap);
	return (t1.len);
}
