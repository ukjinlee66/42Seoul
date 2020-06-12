/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:40:38 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 04:43:31 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		powe(int n)
{
	int		num;

	num = 1;
	n--;
	while (n)
	{
		num *= 10;
		n--;
	}
	return (num);
}

static int		digitcnt(long n)
{
	int		count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*result(char *str)
{
	char *res;

	res = ft_strdup(str);
	free(str);
	return (res);
}

char			*ft_itoa(int n)
{
	char	*ans;
	int		size;
	int		idx;
	long	num;

	idx = 0;
	if (!(ans = malloc(1024)))
		return (0);
	if (n < 0)
	{
		ans[idx++] = '-';
		num = n;
		num = -num;
	}
	else
		num = n;
	size = digitcnt(num) > 0 ? digitcnt(num) : 0;
	while (size > 0)
	{
		ans[idx++] = (num / powe(size)) + '0';
		num %= powe(size);
		size--;
	}
	ans[idx] = '\0';
	return (result(ans));
}
