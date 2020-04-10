/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:13:25 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 14:13:39 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

static int      powe(unsigned int n)
{
    unsigned int num;

    num = 1;
    n--;
    while (n)
    {
        num*=10;
        n--;
    }
    return (num);
}

static int      digitcnt(unsigned int n)
{
    int count;

    count = 1;
    while (n>9)
    {
        n/=10;
        count++;
    }
    return (count);
}

char            *ft_utoa(unsigned int num)
{
    char            *ans;
    int             size;
    int             idx;

    idx = 0;
    ans = malloc(100);
    size = digitcnt(num);
    while (size > 0)
    {
        ans[idx++] = (num / powe(size)) + '0';
        num %= powe(size);
        size--;
    }
    ans[idx] = '\0';
    return (ans);
}