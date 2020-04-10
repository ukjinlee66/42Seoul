/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:30:43 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 15:33:19 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void        parse_format(t_type *t1, va_list *ap, t_form *f1)
{
    size_t index;

    index = 0;
    //형식지정자의 정보가 존재했다면 t1.str문자열에 공간이 할당되어있고 만약 없다면 출력.
    while (t1 -> format[index])
    {
        if (t1 -> format[index] == '%') //형식지정자가 존재할 경우 전부 저장.
        {
            index++;
            check_flag(t1, &index, f1);
            check_width(t1, &index, f1);
            check_precision(t1, &index, f1, ap);
            if (t1 -> error)
                return ;
            check_format(t1, &index, f1, ap);
            init_func(t1, f1);
        }
        else
        {
            write(1, &(t1 -> format[index]), 1);
            t1 -> len++;
        }
        index++;
    }
}