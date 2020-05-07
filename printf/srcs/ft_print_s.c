/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:45:03 by youlee            #+#    #+#             */
/*   Updated: 2020/05/07 17:44:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			left_string(char *dest, t_type *t1, \
		size_t size2, t_form *f1)
{
	size_t		idx;

	idx = 0;
	while (idx < t1->size)
	{
		dest[idx] = t1->ans[idx];
		idx++;
	}
	while (idx < size2)
		dest[idx++] = ' ';
	dest[idx] = '\0';
	print_str(dest, t1, f1);
}

static void			right_string(char *dest, t_type *t1, \
		size_t size2, t_form *f1)
{
	size_t		idx;
	size_t		idx2;

	idx2 = 0;
	idx = 0;
	while (idx < (size2 - t1->size))
		dest[idx++] = ' ';
	while (idx < size2)
		dest[idx++] = t1->ans[idx2++];
	dest[idx] = '\0';
	print_str(dest, t1, f1);
}

static size_t		cal_size(t_form *f1, t_type *t1, int idx)
{
	size_t		size;
	char		*temp;

	size = 0;
	f1->pre = f1->flag[5] < 0 ? t1->size : f1->pre;
	if (f1->exis[2] == true)
	{
		temp = malloc(sizeof(char) * (f1->pre + 1));
		while (idx < (int)f1->pre && t1->ans[idx])
		{
			temp[idx] = t1->ans[idx];
			idx++;
		}
		temp[idx] = '\0';
		t1->ans = temp;
		size = f1->pre < t1->size ? f1->pre : t1->size;
		t1->size = size;
	}
	else
		size = t1->size;
	if (f1->width > size)
		return (f1->width);
	else
		return (size);
}

static void			null_case(t_form *f1, t_type *t1, int idx)
{
	char		nu[7];

	nu[0] = '(';
	nu[1] = 'n';
	nu[2] = 'u';
	nu[3] = 'l';
	nu[4] = 'l';
	nu[5] = ')';
	nu[6] = '\0';
	if (f1->exis[2] == true && f1->flag[5] == 0)
	{
		t1->ans = malloc(sizeof(char) * (f1->pre + 1));
		while (idx < (int)f1->pre && f1->exis[2] && nu[idx])
		{
			t1->ans[idx] = nu[idx];
			idx++;
		}
		t1->ans[idx] = '\0';
	}
	else
		t1->ans = ft_strdup((const char*)nu);
}

void				printf_str(t_form *f1, va_list *ap, t_type *t1)
{
	char		*str;
	char		*temp;
	size_t		size;

	str = va_arg(*ap, char*);
	if (f1->pre == 0 && f1->exis[2] && f1->flag[5] == 0)
		return (special(f1, t1, 0));
	if (str == NULL)
		null_case(f1, t1, 0);
	else
		t1->ans = str;
	t1->size = ft_strlen((const char*)t1->ans);
	size = cal_size(f1, t1, 0);
	temp = malloc(sizeof(char) * size);
	f1->flag[2] > 0 ? left_string(temp, t1, size, f1) : \
		right_string(temp, t1, size, f1);
}
