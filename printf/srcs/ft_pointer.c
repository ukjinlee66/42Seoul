/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 16:15:39 by youlee            #+#    #+#             */
/*   Updated: 2020/05/06 12:36:03 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*make_str(unsigned long long temp2)
{
	char				*str;
	unsigned long long	mod;
	size_t				idx;

	str = (char*)malloc(sizeof(char) * 4096);
	idx = 0;
	while (true)
	{
		mod = temp2 % 16;
		if (mod < 10)
			str[idx++] = 48 + mod;
		else
			str[idx++] = 97 + (mod - 10);
		temp2 /= 16;
		if (temp2 == 0)
			break ;
	}
	str[idx] = '\0';
	return (str);
}

static char		*put_str(size_t nusize, char *temp, t_type *t1, \
t_form *f1)
{
	size_t				idx;
	size_t				idx2;

	idx2 = 0;
	idx = 0;
	if (f1->flag[2] > 0)
	{
		while (idx < ft_strlen((const char*)t1->ans))
			temp[idx++] = t1->ans[idx2++];
		while (idx < t1->size)
			temp[idx++] = ' ';
		temp[idx] = '\0';
	}
	else
	{
		while (idx < nusize)
			temp[idx++] = ' ';
		while (idx < t1->size && t1->ans[idx2])
			temp[idx++] = t1->ans[idx2++];
		temp[idx] = '\0';
	}
	return (temp);
}

static char		*cal_size(char *str, t_form *f1, t_type *t1, \
unsigned long long temp2)
{
	char				*temp;
	size_t				nusize;

	if (temp2 == 0)
		if (f1->exis[2])
			str = "0x";
		else
			str = "0x0";
	else
		str =make_str(temp2);
	if (temp2 != 0)
	{
		ft_strrev(&str);
		t1->ans = ft_strjoin((const char*)"0x", str);
		free(str);
	}
	else
		t1->ans = str;
	t1->size = ft_strlen((const char *)t1->ans) >= f1->width ? \
		ft_strlen((const char *)t1->ans) : f1->width;
	temp = (char*)malloc(sizeof(char) * (t1->size) + 1);
	nusize = (t1->size) - (ft_strlen((const char*)t1->ans));
	put_str(nusize, temp, t1, f1);
	return (temp);
}

void			printf_ptr(t_form *f1, va_list *ap, t_type *t1)
{
	char				*str;
	unsigned long long	temp2;

	str = NULL;
	temp2 = va_arg(*ap, long long);
	str = cal_size(str, f1, t1, temp2);
	print_str(str, t1, f1);
	if (temp2 != 0)
		free(t1->ans);
}
