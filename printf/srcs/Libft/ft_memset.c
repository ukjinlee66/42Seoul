/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:03:46 by youlee            #+#    #+#             */
/*   Updated: 2020/04/08 21:27:00 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			idx;
	unsigned char	*res;

	res = (unsigned char *)ptr;
	idx = 0;
	while (idx < num)
	{
		*res = (unsigned char)value;
		idx++;
		res++;
	}
	return (ptr);
}
