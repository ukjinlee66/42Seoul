/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:05:32 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 18:27:17 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	idx;
	size_t	idx2;
	size_t	size;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	idx = 0;
	idx2 = 0;
	if (!(ans = malloc(sizeof(char) * size)))
		return (NULL);
	while (s1[idx])
	{
		ans[idx] = s1[idx];
		idx++;
	}
	while (s2[idx2])
		ans[idx++] = s2[idx2++];
	ans[idx] = 0;
	return (ans);
}
