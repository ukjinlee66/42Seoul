/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:07:39 by youlee            #+#    #+#             */
/*   Updated: 2020/04/05 02:24:31 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	int		size;
	int		idx;

	idx = 0;
	size = ft_strlen(str);
	if (!(res = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (str[idx])
	{
		res[idx] = str[idx];
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
