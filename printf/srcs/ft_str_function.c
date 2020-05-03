/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 00:54:15 by youlee            #+#    #+#             */
/*   Updated: 2020/05/03 13:07:48 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	special(t_form *f1, t_type *t1, int idx)
{
	if (f1->width == 0)
	{
		if (f1->flag[3] > 0)
		{
			write(1, "+", 1);
			t1->len++;
		}
		if (f1->flag[4] > 0)
		{
			write(1, " ", 1);
			t1->len++;
		}
	}
	else
	{
		while (idx < (int)f1->width - 1)
		{	
			write(1, " ", 1);
			idx++;
		}
		f1->flag[3] > 0 ? write(1, "+", 1) : write(1, " ", 1);
		t1->len++;
		t1->len += idx;
	}
}

void		ft_strrev(char **strr)
{
	size_t		nusize;
	size_t		idx;
	char		c;
	char		*str;

	str = *strr;
	idx = 0;
	nusize = ft_strlen((const char*)str) - 1;
	while (idx < (nusize + 1) / 2)
	{
		c = str[idx];
		str[idx] = str[nusize - idx];
		str[nusize - idx] = c;
		idx++;
	}
}
