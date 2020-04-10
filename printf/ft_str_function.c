/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 00:54:15 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 00:57:25 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void        ft_strrev(char *str)
{
    size_t      nusize;
    size_t      idx;
    char        c;

    idx = 0;
    nusize = ft_strlen((const char*)str) - 1;
    while (idx < nusize / 2)
    {
        c = str[idx];
        str[idx] = str[nusize - idx];
        str[nusize - idx] = c;
        idx++;
    }
}