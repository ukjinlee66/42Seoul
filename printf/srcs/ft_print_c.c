/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:46:05 by youlee            #+#    #+#             */
/*   Updated: 2020/05/03 15:35:13 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		left_char(char *dest, t_type *t1, size_t size, t_form *f1)
{
	size_t	idx;

	f1->exis[3]=false;
	idx = 1;
	dest[0] = t1->ans[0];
	if (size == 1)
	{
		write(1, &(dest[0]), 1);
		t1->len++;
		free(dest);
	}
	else
	{
		while (idx < size)
			dest[idx++] = ' ';
		dest[idx] = '\0';
		write(1, dest, size);
		t1->len += size;
		free(dest);
		//print_str(dest, t1, f1);
	}
}
#include <stdio.h>
static void		right_char(char *dest, t_type *t1, size_t size, t_form *f1)
{
	int		idx;
	int		size2;

	f1->exis[3]=false;
	idx = size - 1;
	size2 = idx;
	if (idx == 0)
	{
		dest[0] = t1->ans[0];
		dest[1] = '\0';
		write(1, &(dest[0]), 1);
		t1->len++;
		free(dest);
	}
	else
	{
		dest[idx--] = t1->ans[0];
		while (idx > 0)
			dest[idx--] = ' ';
		dest[idx] = ' ';
		write(1, dest, size2 + 1);
		t1->len += size2 + 1;
		free(dest);
		//print_str(dest, t1, f1);
	}
}

void			printf_char(t_form *f1, va_list *ap, t_type *t1)
{
	char	*temp;
	size_t	size;
	char	ch2[2];

	size = 0;
	ch2[0] = (char)va_arg(*ap, int);
	ch2[0] = ch2[0];
	ch2[1] = '\0';
	t1->ans = ch2;
	t1->size = 1;
	size = t1->size >= f1->width ? t1->size : f1->width;
	temp = malloc(sizeof(char) * (size + 1));
	temp[size] = '\0';
	f1->flag[2] > 0 ? left_char(temp, t1, size, f1) : \
		right_char(temp, t1, size, f1);
}
