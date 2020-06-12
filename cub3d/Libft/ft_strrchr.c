/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:36:35 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:49:51 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		size;
	char	*st;

	st = (char*)str;
	size = 0;
	while (str[size])
		++size;
	if (c == '\0')
		return (st + size);
	while (size >= 0)
	{
		if (st[size] == c)
			return (st + size);
		size--;
	}
	return (NULL);
}
