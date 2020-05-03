/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:52:20 by youlee            #+#    #+#             */
/*   Updated: 2020/05/02 11:52:20 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_flag(t_type *t1, size_t *idx, t_form *f1)
{
	while (t1->format[*idx] == '#' || t1->format[*idx] == '0' || \
	t1->format[*idx] == '+' || t1->format[*idx] == '-' || \
	t1->format[*idx] == ' ')
	{
		if (f1->exis[0] == false)
			f1->exis[0] = true;
		if (t1->format[*idx] == '#')
			f1->flag[0]++;
		else if (t1->format[*idx] == '0')
			f1->flag[1]++;
		else if (t1->format[*idx] == '-')
			f1->flag[2]++;
		else if (t1->format[*idx] == '+')
			f1->flag[3]++;
		else if (t1->format[*idx] == ' ')
			f1->flag[4]++;
		(*idx)++;
	}
	//if ((f1->flag[1] > 0 && f1->flag[2] > 0) || \
	//		(f1->flag[3] > 0 && f1->flag[4] > 0))
	//	t1->error = true;
	return (0);
}
