/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:04:46 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:12:17 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			idx;
	unsigned char	*pt1;
	unsigned char	*pt2;

	idx = 0;
	pt1 = (unsigned char*)ptr1;
	pt2 = (unsigned char*)ptr2;
	while (idx < num)
	{
		if (pt1[idx] != pt2[idx])
			return ((int)(pt1[idx] - pt2[idx]));
		idx++;
	}
	return (0);
}
