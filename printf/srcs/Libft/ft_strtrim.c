/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:25:03 by youlee            #+#    #+#             */
/*   Updated: 2020/04/07 01:56:40 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool		isset(char a, char const *set)
{
	int		index;

	index = 0;
	while (set[index])
	{
		if (a == set[index])
			return (true);
		index++;
	}
	return (false);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		index2;
	int		index3;
	char	*ans;

	if (!s1 || !set)
		return (ft_strdup(""));
	index = 0;
	index2 = ft_strlen(s1) - 1;
	index3 = 0;
	while (isset(s1[index], set) && s1[index])
		++index;
	while (isset(s1[index2], set) && index2)
		--index2;
	if ((index2 - index) <= 0)
		return (ft_strdup(""));
	if (!(ans = malloc(sizeof(char) * ((index2 - index) + 2))))
	{
		ans = malloc(0);
		return (ans);
	}
	while (index <= index2)
		ans[index3++] = s1[index++];
	ans[index3] = '\0';
	return (ans);
}
