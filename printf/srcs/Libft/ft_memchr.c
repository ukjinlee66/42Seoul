/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:39:23 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 01:11:55 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t num)
{
	size_t				idx;
	unsigned char		*sr;

	sr = (unsigned char*)src;
	idx = 0;
	while (idx < num)
	{
		if (sr[idx] == (unsigned char)c)
			return (&sr[idx]);
		idx++;
	}
	return (NULL);
}
