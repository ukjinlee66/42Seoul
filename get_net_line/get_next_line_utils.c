/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 10:32:48 by youlee            #+#    #+#             */
/*   Updated: 2020/04/10 16:40:54 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strdup(char *str)
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

char	*ft_strjoin(char *s1, char *s2)
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

int		ft_strchr(char *str, char c)
{
	int		idx;
	char	*st;

	st = (char*)str;
	idx = 0;
	while (st[idx])
	{
		if (st[idx] == c)
			return (idx);
		idx++;
	}
	if (st[idx] == '\0' && c == '\0')
		return (idx);
	return (-1);
}
