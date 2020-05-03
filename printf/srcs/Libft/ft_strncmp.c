/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:38 by youlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:43:08 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char*)str1;
	st2 = (unsigned char*)str2;
	while ((*st1 != '\0' || *st2 != '\0') && num)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
		num--;
	}
	return (0);
}
