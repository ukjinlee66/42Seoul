/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:32:41 by youlee            #+#    #+#             */
/*   Updated: 2020/04/06 21:12:32 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		constlen(char const *str)
{
	int				size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ans;
	unsigned int	idx;
	unsigned int	s_size;
	unsigned int	len2;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len2 = (unsigned int)len;
	s_size = constlen(s);
	idx = 0;
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[idx] && idx < len2)
	{
		ans[idx] = s[start + idx];
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
