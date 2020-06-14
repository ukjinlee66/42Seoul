/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:33:19 by youlee            #+#    #+#             */
/*   Updated: 2020/06/14 21:38:33 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

int			ft_endlen.c(char *str, char *end)
{
	int		len;
	int		end_len;

	len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (end_len > len)
		return (0);
	return (!ft_strcmp(str + len - end_len, end);
}
