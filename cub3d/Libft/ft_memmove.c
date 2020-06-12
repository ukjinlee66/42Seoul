/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:14:19 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 01:04:48 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*de;
	const unsigned char	*sr;
	size_t				idx;

	idx = 0;
	if (!dest && !src)
		return (dest);
	de = (unsigned char*)dest;
	sr = (unsigned char*)src;
	if (sr < de)
		while (num-- > 0)
			de[num] = sr[num];
	else
		while (idx < num)
		{
			de[idx] = sr[idx];
			idx++;
		}
	return (dest);
}
