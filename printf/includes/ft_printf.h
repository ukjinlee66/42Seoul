/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:13:21 by youlee            #+#    #+#             */
/*   Updated: 2020/05/03 09:29:24 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

/*
** **flag count**
** flag[0] : '#'
** flag[1] : '0'
** flag[2] : '-'
** flag[3] : '+'
** flag[4] : ' '
** flag[5] : negative wild
**
**  **exis conut**
**  format existence possibility
**  exis[0] : check flag
**  exis[1] : check width
**  exis[2] : check precision
**  exis[3] : wild
*/
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int arg);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int arg);
void				*ft_memccpy(void *dest, const void *src, int c, size_t num);
void				*ft_memchr(const void *src, int c, size_t num);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memset(void *ptr, int value, size_t num);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t num);
size_t				ft_strlcpy(char *dest, const char *src, size_t num);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strnstr(const char *dest, const char *src, size_t len);
char				*ft_strrchr(const char *str, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_type
{
	char			*ans;
	const char		*format;
	bool			error;
	size_t			size;
	int				len;
}					t_type;
typedef struct		s_form
{
	bool			exis[4];
	int				flag[6];
	size_t			width;
	size_t			pre;
	bool			neg;
}					t_form;
void				parse_format(t_type *t1, va_list *ap, t_form *f1);
int					ft_printf(const char *format, ...);
void				check_width(t_type *t1, size_t *idx, t_form *f1);
int					check_flag(t_type *t1, size_t *idx, t_form *f1);
void				check_precision(t_type *t1, size_t *idx, \
		t_form *f1, va_list *ap);
void				check_format(t_type *t1, size_t *index, t_form *f1, \
		va_list *ap);
void				left_put_flag(char *dest, t_form *f1, char ch, \
		size_t *index);
void				right_put_flag(char *dest, t_form *f1, char ch, \
		size_t *index);
void				print_dec(t_form *f1, va_list *ap, t_type *t1);
void				printf_str(t_form *f1, va_list *ap, t_type *t1);
void				printf_char(t_form *f1, va_list *ap, t_type *t1);
void				printf_percent(t_form *f1, t_type *t1);
void				init_typ(t_type *tt, t_form *ff);
void				printf_ptr(t_form *f1, va_list *ap, t_type *t1);
void				right_put_sign_zero(char *dest, t_form *f1, \
		size_t *idx, t_type *t1);
void				right_put_sign_notzero(char *dest, t_form *f1, \
		size_t *idx, t_type *t1);
void				print_str(char *str, t_type *t1, t_form *f1);
void				print_unsigned(t_form *f1, va_list *ap, \
		t_type *t1, size_t *index);
void				ft_strrev(char **strr);
char				*ft_utoa(unsigned int num);
void				ft_compare(t_form *f1, t_type *t1, \
		size_t *index, char *str);
void				init_func(t_type *tt, t_form *ff);
void				special(t_form *f1, t_type *t1, int idx);
#endif
