/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:51:44 by youlee            #+#    #+#             */
/*   Updated: 2020/05/04 19:40:09 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_compare(t_form *f1, t_type *t1, size_t *index, char *str)
{
	if (f1->pre > 0 && f1->exis[2])
		f1->flag[1] = 0;
	if (t1->format[*index] == 'X')
		str = ft_strjoin((void*)"0X", t1->ans);
	else if (t1->format[*index] == 'x')
		str = ft_strjoin((void*)"0x", t1->ans);
	else
		str = ft_strdup((const char*)t1->ans);
	free(t1->ans);
	t1->ans = str;
}
