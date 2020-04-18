/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:57:10 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:07:11 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned char	*de;
	unsigned char	*sr;
	int				idx;

	idx = 0;
	de = (unsigned char*)dest;
	sr = (unsigned char*)src;
	while (num)
	{
		if (sr[idx] == (unsigned char)c)
		{
			de[idx] = sr[idx];
			return (dest + idx + 1);
		}
		de[idx] = sr[idx];
		idx++;
		num--;
	}
	return (NULL);
}
