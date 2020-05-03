/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:30:41 by youlee            #+#    #+#             */
/*   Updated: 2020/04/26 01:49:30 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		left_put_flag(char *dest, t_form *f1, char ch, size_t *index)
{
	if (f1->flag[0] > 0 && f1->flag[3] <= 0 && \
	f1->flag[4] <= 0)
	{
		if (ch == 'x')
		{
			dest[(*index)++] = '0';
			dest[(*index)++] = 'x';
		}
		else if (ch == 'X')
		{
			dest[(*index)++] = '0';
			dest[(*index)++] = 'X';
		}
	}
}
