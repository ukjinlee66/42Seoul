/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:54:36 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:25:44 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	idx;
	char	*st;

	st = (char*)str;
	idx = 0;
	while (st[idx])
	{
		if (st[idx] == c)
			return (st + idx);
		idx++;
	}
	if (st[idx] == '\0' && c == '\0')
		return (st + idx);
	return (NULL);
}
