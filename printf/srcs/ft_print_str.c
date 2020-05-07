/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:20:12 by youlee            #+#    #+#             */
/*   Updated: 2020/05/07 20:05:13 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_str(char *str, t_type *t1, t_form *f1)
{
	size_t		size;
	char		*ans;
	bool		ch;

	ch = f1->width <= t1->size ? true : false;
	if (f1->neg == true && ch)
		ans = ft_strjoin("-", str);
	else if (f1->flag[3] > 0 && ch)
		ans = ft_strjoin("+", str);
	else if (f1->flag[4] > 0 && ch)
		ans = ft_strjoin(" ", str);
	else
		ans = ft_strdup((const char*)str);
	free(str);
	size = ft_strlen((const char*)ans);
	t1->len += size;
	write(1, ans, size);
	free(ans);
}
