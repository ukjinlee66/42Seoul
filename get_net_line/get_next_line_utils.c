/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 10:32:48 by youlee            #+#    #+#             */
/*   Updated: 2020/04/16 19:42:38 by youlee           ###   ########.fr       */
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

int		ft_strlen(char *str, char **buf2, int fd, int ch)
{
	int size;

	size = 0;
	if (ch)
	{
		while (str[size] != '\0')
			size++;
		return (size);
	}
	else
	{
		while (size < fd + 2)
		{
			free(buf2[size]);
			buf2[size++] = NULL;
		}
		free(buf2);
		return (0);
	}
}

char	*ft_strdup(char *str, int ch, char **str2, char *temp)
{
	char	*res;
	int		size;
	int		idx;

	if (ch == 1)
	{
		idx = 0;
		res = NULL;
		size = ft_strlen(str, NULL, 0, 1);
		if (!(res = malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (str[idx] != '\0')
		{
			res[idx] = str[idx];
			idx++;
		}
		res[idx] = '\0';
		return (res);
	}
	else
	{
		free(*str2);
		*str2 = temp;
		return (0);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	size_t	idx;
	size_t	idx2;
	size_t	size;

	size = ft_strlen(s1, NULL, 0, 1) + ft_strlen(s2, NULL, 0, 1) + 1;
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

int		ft_strchr(char *str, char c, char **buf2, int fd)
{
	int		idx;
	char	*st;

	idx = 0;
	if (fd == 0)
	{
		st = (char*)str;
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
	else
	{
		while (idx < fd + 1)
			buf2[idx++] = ft_strdup("\0", 1, 0, 0);
		return (0);
	}
}
