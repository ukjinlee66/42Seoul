/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:45:03 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 15:57:29 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

static void         left_string(char *dest, t_type *t1, size_t size2)
{
    size_t      idx;

    idx = 0;
    while (idx < t1 -> size)
    {
        dest[idx] = t1 -> ans[idx];
        idx++;
    }
    while (idx < size2)
        dest[idx++] = ' ';
    dest[idx] = '\0';
    print_str(dest, t1);
}

static void         right_string(char *dest, t_type *t1, size_t size2)
{
    size_t      idx;
    size_t      idx2;

    idx2 = 0;
    idx = 0;
    while (idx < (size2 - t1 -> size))
        dest[idx++] = ' ';
    while (idx < size2)
        dest[idx++] = t1 -> ans[idx2++];
    dest[idx] = '\0';
    print_str(dest, t1);
}

static size_t       cal_size(t_form *f1, t_type *t1)
{
    size_t      size;

    size = 0;
    if ((t1 -> size > f1 -> pre) && f1 -> exis[2] && f1 -> flag[5] == 0)
    {
        size = f1 -> pre;
        t1 -> size = size;
    }
    else
        size = t1 -> size;
    if (f1 -> width > size)
        return (f1 -> width);
    else
        return (size);
}

void                printf_str(t_form *f1, va_list *ap, t_type *t1)
{
    char        *str;
    char        *temp;
    size_t      size;

    str = va_arg(*ap, char*);
    if (f1 -> exis[2] && str == NULL)
    {
        t1 -> ans = f1 -> pre >= 6 ? "(null)" : "";
        t1 -> size = f1 -> pre >= 6 ? 6 : 0;
        t1 -> ans = f1 -> flag[5] < 0 ? "(null)" : "";
        t1 -> size = f1 -> flag[5] < 0 ? 6 : 0;
    }
    else if (!f1 -> exis[2] && str == NULL)
    {
        t1 -> ans = "(null)";
        t1 -> size = 6;
    }
    else
    {
        t1 -> ans = str;
        t1 -> size = ft_strlen((const char*)str);
    }
    size = cal_size(f1, t1);
    temp = malloc(sizeof(char) * size);
    temp[size] = '\0';
    f1 -> flag[2] > 0 ? left_string(temp, t1, size) \
    : right_string(temp, t1, size);
}