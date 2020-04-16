/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 15:06:35 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 14:57:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

static void put_zero(t_type *t1, t_form *f1)
{
    char        *str;
    int         zero;

    zero = (int)(f1 -> pre) - (int)(t1 -> size);
    while (zero--)
    {
        str = ft_strjoin((const char*)"0", (const char *)t1 -> ans);
        free(t1 -> ans);
        t1 -> ans = str;
    }
}

static void change_base(t_type *t1, char ch, unsigned int num)
{
    char        *str;
    size_t      idx;
    int         mod;

    ch -= 'X';
    idx = 0;
    str = (char*)malloc(sizeof(char) * 1024);
    num = ft_atoi((const char*)t1 -> ans);
    while (num != 0)
    {
        mod = num % 16;
        if (mod < 10)
            str[idx++] = 48 + mod;
        else
            str[idx++] = 65 + ch + (mod - 10);
        num /= 16;
    }
    str[idx] = '\0';
    ft_strrev(str);
    free(t1 -> ans);
    t1 -> ans = str;
}

static void left_copy(char *dest, t_type *t1)
{
    size_t      idx;
    size_t      idx2;

    idx2 = 0;
    idx = 0;
    while (idx < ft_strlen((const char*)t1 -> ans))
        dest[idx++] = t1->ans[idx2++];
    while (idx < t1 -> size)
        dest[idx++] = ' ';
    dest[idx] = '\0';
    print_str(dest, t1);
    free(t1 -> ans);
}

static void right_copy(char *dest, t_type *t1, t_form *f1, size_t *index)
{
    size_t      idx;
    size_t      idx2;

    idx = 0;
    idx2 = 0;
    if (f1 -> flag[1] > 0 && (t1 -> format[*index] == 'x' || t1 -> format[*index] == 'X'))
    {
        dest[idx++] = '0';
        dest[idx++] = t1 -> format[*index] == 'x' ? 'x' : 'X';
    }
    if (f1 -> flag[1] > 0)
        while (idx < (t1 -> size) - ft_strlen((const char*)t1 -> ans) && \
        dest[idx] == '\x0')
            dest[idx++] = '0';
    else
        while (idx < t1 -> size - ft_strlen((const char*)t1 -> ans))
            dest[idx++] = ' ';
    while (idx < t1 -> size)
        dest[idx++] = t1 -> ans[idx2++];
    dest[idx] = '\0';
    print_str(dest, t1);
    free(t1 -> ans);
}

void        print_unsigned(t_form *f1, va_list *ap, t_type *t1, size_t *index)
{
    unsigned int    num;
    char            *str;
    char            *dest;

    str = NULL;
    num = va_arg(*ap, int);
    t1 -> ans = ft_utoa(num);
    t1 -> size = ft_strlen((const char*)t1 -> ans);
    if (t1 -> format[*index] == 'X' || t1 -> format[*index] == 'x')
        change_base(t1, t1 -> format[*index], num);
    if (ft_strlen((const char*)t1 -> ans) < f1 -> pre)
        put_zero(t1, f1);
    ft_compare(f1, t1, index, str);
    t1 -> size = ft_strlen((const char*)t1 -> ans) >= f1 -> width ? \
    ft_strlen((const char*)t1 -> ans) : f1 -> width;
    dest = (char*)malloc(sizeof(char) * (t1 -> size));
    dest[t1 -> size] = '\0';
    f1 -> flag[2] > 0 ? left_copy(dest, t1) : right_copy(dest, t1, f1, index);
}