/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:20:12 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 15:16:01 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void            print_str(char *str, t_type *t1)
{
    size_t      size;

    size = ft_strlen((const char*)str);
    t1 -> len += size;
    write(1, str, size);
    free (str);
}