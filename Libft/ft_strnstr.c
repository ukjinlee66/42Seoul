/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:36:29 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:49:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t num)
{
	size_t	idx;
	size_t	idx2;

	if (!*src)
		return ((char*)dest);
	idx = 0;
	while (dest[idx] != '\0' && (idx < num))
	{
		idx2 = 0;
		while (dest[idx + idx2] != '\0' && (dest[idx + idx2] == src[idx2]) &&
		(idx + idx2) < num)
		{
			if (src[idx2 + 1] == '\0')
				return ((char*)&dest[idx]);
			idx2++;
		}
		idx++;
	}
	return (0);
}
