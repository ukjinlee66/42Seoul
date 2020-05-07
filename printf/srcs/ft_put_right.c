/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:32:50 by youlee            #+#    #+#             */
/*   Updated: 2020/05/07 20:41:48 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		right_put_sign_notzero(char *dest, t_form *f1, size_t *idx, \
		t_type *t1)
{
	size_t		idx2;

	idx2 = 0;
	if (f1->neg || f1->flag[3] || f1->flag[2] || \
			f1->flag[4])
		t1->size++;
	while (*idx < (f1->width - (t1->size)))
		dest[(*idx)++] = ' ';
	if (f1->flag[3] > 0)
		dest[(*idx)++] = f1->neg == true ? '-' : '+';
	else if (f1->flag[4] > 0)
		dest[(*idx)++] = f1->neg == true ? '-' : ' ';
	else if (f1->neg)
		dest[(*idx)++] = '-';
	while (*idx < f1->width && t1->ans[idx2])
		dest[(*idx)++] = t1->ans[idx2++];
	dest[(*idx)] = '\0';
}

void		right_put_sign_zero(char *dest, t_form *f1, size_t *idx, t_type *t1)
{
	size_t		idx2;

	idx2 = 0;
	if (f1->flag[3] > 0 && f1->pre == 0)
		dest[(*idx)++] = f1->neg == true ? '-' : '+';
	else if (f1->flag[4] > 0 && f1->pre == 0)
		dest[(*idx)++] = f1->neg == true ? '-' : ' ';
	else if (f1->neg && f1->flag[1] > 0 && f1->pre == 0)
		dest[(*idx)++] = '-';
	while (*idx < (f1->width - (t1->size)) && f1->pre == 0)
		dest[(*idx)++] = '0';
	while (*idx < (f1->width - (t1->size)) && f1->pre > 0)
		dest[(*idx)++] = ' ';
	if (f1->flag[3] > 0 && f1->pre > 0)
		dest[(*idx)++] = f1->neg == true ? '-' : '+';
	else if (f1->flag[4] > 0 && f1->pre > 0)
		dest[(*idx)++] = f1->neg == true ? '-' : ' ';
	else if (f1->neg && f1->pre > 0)
		dest[(*idx) - 1] = '-';
	while (*idx < f1->width && t1->ans[idx2])
		dest[(*idx)++] = t1->ans[idx2++];
	dest[(*idx)] = '\0';
}
