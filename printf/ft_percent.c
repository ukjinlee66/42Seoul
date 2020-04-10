/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:46:24 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 00:33:53 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void        printf_percent(t_type *t1)
{
    char    *ch;

    ch = malloc(sizeof(char) * 2);

    ch[0] = '%';
    ch[1] = '\0';
    t1 -> ans = ch;
    t1 -> size = 1;
    print_str(t1 -> ans, t1);
}