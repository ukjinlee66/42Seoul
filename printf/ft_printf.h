/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:13:21 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 15:28:29 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include "Libft/libft.h"

/*
 * **flag count**
 * flag[0] : '#'
 * flag[1] : '0'
 * flag[2] : '-'
 * flag[3] : '+'
 * flag[4] : ' '
 * flag[5] : negative wild
 *
 *  **exis conut**
 *  format existence possibility
 *  exis[0] : check flag
 *  exis[1] : check width
 *  exis[2] : check precision
 *  exis[3] : wild
*/

typedef struct  s_type
{
    char            *ans;
    const char      *format;
    bool            error;
    size_t          size;
    int             len;
}               t_type;

typedef struct  s_form
{
    bool            exis[4];
    int             flag[6];
    size_t          width;
    size_t          pre;
    bool            neg;
}               t_form;

void                parse_format(t_type *t1, va_list *ap, t_form *f1);
int                 ft_printf(const char *format, ...);
void                check_width(t_type *t1, size_t *idx, t_form *f1);
int                 check_flag(t_type *t1, size_t *idx, t_form *f1);
void                check_precision(t_type *t1, size_t *idx, t_form *f1, va_list *ap);
void                check_format(t_type *t1, size_t *index,t_form *f1, va_list *ap);
void                left_put_flag(char *dest, t_form *f1, char ch, size_t *index);
void                right_put_flag(char *dest, t_form *f1, char ch, size_t *index);
void                print_dec(t_form *f1, va_list *ap, t_type *t1, size_t *index);
void                printf_str(t_form *f1, va_list *ap, t_type *t1);
void                printf_char(t_form *f1, va_list *ap, t_type *t1);
void                printf_percent(t_type *t1);
void                init_typ(t_type *tt, t_form *ff);
void                printf_ptr(t_form *f1, va_list *ap, t_type *t1);
void                right_put_sign_zero(char *dest, t_form *f1, size_t *idx, t_type *t1);
void                right_put_sign_notzero(char *dest, t_form *f1, size_t *idx, t_type *t1);
void                print_str(char *str, t_type *t1);
void                print_unsigned(t_form *f1, va_list *ap, t_type *t1, size_t *index);
void                ft_strrev(char *str);
char                *ft_utoa(unsigned int num);
void                ft_compare(t_form *f1, t_type *t1, size_t *index, char *str);
void                init_func(t_type *tt, t_form *ff);

#endif
