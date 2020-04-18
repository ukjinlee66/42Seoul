/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:27:18 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 04:31:05 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	int		size;
	int		idx;

	idx = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (idx < size)
	{
		ans[idx] = f(idx, s[idx]);
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
