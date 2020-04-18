/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:48:42 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 18:32:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t num)
{
	size_t	size;
	size_t	idx;

	size = 0;
	idx = 0;
	if (!dest || !src)
		return (0);
	while (src[size])
		size++;
	if (!num)
		return (size);
	while (src[idx] && idx < num - 1)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (size);
}
