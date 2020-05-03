/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:46:24 by youlee            #+#    #+#             */
/*   Updated: 2020/05/02 12:38:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_zero(t_type *t1, t_form *f1)
{
	char	*str;
	int		zero;

	zero = (int)(f1->width) - 1;
	if (zero >= 1)
	{
		while (zero--)
		{
			str = ft_strjoin((const char*)"0", (const char *)t1->ans);
			free(t1->ans);
			t1->ans = str;
		}
	}
}

static void	left_copy(char *dest, t_type *t1, t_form *f1)
{
	size_t	idx;
	size_t	idx2;

	idx2 = 0;
	idx = 0;
	while (t1->ans[idx2] != '\0')
		dest[idx++] = t1->ans[idx2++];
	while (idx < f1->width)
		dest[idx++] = ' ';
	dest[idx] = '\0';
	write(1, dest, t1->size);
	t1->len += t1->size;
	free(dest);
	free(t1->ans);
}

static void	right_copy(char *dest, t_type *t1, t_form *f1)
{
	size_t	idx;

	idx = 0;
	t1->len += t1->size;
	if (f1->flag[1] == 0)
	{
		while (idx < f1->width - 1)
			dest[idx++] = ' ';
		dest[idx++] = t1->ans[0];
		dest[idx] = t1->ans[1];
		write(1, dest, t1->size);
		free(dest);
		free(t1->ans);
	}
	else
	{
		write(1, t1->ans, t1->size);
		free(t1->ans);
		free(dest);
	}
}
#include <stdio.h>
void		printf_percent(t_form *f1, t_type *t1)
{
	char	*ch;
	char	*str;

	ch = malloc(sizeof(char) * 2);
	ch[0] = '%';
	ch[1] = '\0';
	t1->ans = ch;
	t1->size = (f1->width > 1) ? f1->width : 1;
	if (f1->flag[1] > 0 && f1->flag[2] == 0)
		put_zero(t1, f1);
	if (t1->size == 1)
	{
		write(1, "%", 1);
		t1->len++;
	}
	else
	{
		str = malloc(sizeof(char) * f1->width);
		f1->flag[2] > 0 ? left_copy(str, t1, f1) : right_copy(str, t1, f1);
	}
}
