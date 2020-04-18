/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:28:45 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 02:20:39 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		ft_isspace2(int ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' ||
	ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int					ans;
	int					idx;
	int					sign;
	unsigned long long	check;

	idx = 0;
	ans = 0;
	check = 0;
	while (ft_isspace2(str[idx]))
		idx++;
	sign = str[idx] == '-' ? -1 : 1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] && ('9' >= str[idx] && str[idx] >= '0'))
	{
		ans = ans * 10 + (str[idx] - '0');
		if (((check * 10) + (str[idx] - '0')) > LLONG_MAX)
			return (sign == 1 ? -1 : 0);
		check = check * 10 + (str[idx] - '0');
		idx++;
	}
	return (ans * sign);
}
