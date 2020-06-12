/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:56:35 by youlee            #+#    #+#             */
/*   Updated: 2020/04/07 01:35:34 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t num)
{
	size_t	ans;
	size_t	size;
	size_t	idx;
	size_t	size2;

	size = ft_strlen((char*)src);
	size2 = 0;
	while (dest[size2] && size2 < num)
		size2++;
	if (size2 == num)
		return (size + size2);
	if (!num)
		return (size);
	idx = 0;
	ans = 0;
	while (src[idx] && size2 < num - 1)
		dest[size2++] = src[idx++];
	dest[size2] = '\0';
	while (src[idx++])
		size2++;
	return (size2);
}
