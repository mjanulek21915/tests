/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

# define CONV "cspdiuxX%"
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16A "0123456789ABCDEF"

# define TEST "cesi est un test"

typedef struct			s_type
{
	int					is_percent;
	int					is_left;
	int					is_signed;
	int					is_space;
	int					is_width;
	int					is_precision;
	int					is_zero;
	int					is_star;
	int					is_prec_orig;
	int					is_width_orig;
	int					print_none;
	int					width_star;
	int					prec_star;
	char				padding;
	int					width;
	int					precision;
	char				type;
	char				sign;
	int					len;
	int					prec_len;
	int					pad_len;
	long long			temp;
	char				*ptr_temp;
	char				*ptr;
}						t_type;

int						ft_printf(const char *str, ...);
void					ft_read(char **str, va_list va, int *rst);
int						ft_pf_strlen(char *str);
void					ft_write(t_type *type, va_list va, int *rst);
void					ft_pf_putchar(char *ptr, int *rst);
void					ft_pf_putstr(char *str, int *rst);
int						ft_pf_write_get_sign(long long *temp, t_type *type);
int						ft_pf_write_nlen(unsigned long long n, int base);
void					ft_pf_write_n(char *str, int n, int *rst);
void					ft_pf_write_uint(va_list vl, t_type *type, int *rst);
void					ft_pf_write_str(va_list vl, t_type *type, int *rst);
void					ft_pf_write_put_base(unsigned long long n,
char *base, int *rst);
void					ft_pf_write_ptr(va_list vl, t_type *type, int *rst);
void					ft_pf_write_percent(t_type *type, int *rst);
void					ft_pf_write_padding(int n, char c, int *rst);
void					ft_pf_write_int(va_list vl, t_type *type, int *rst);
void					ft_pf_write_hex(va_list vl, t_type *type, int *rst);
void					ft_pf_write_hex_a(va_list vl, t_type *type, int *rst);
void					ft_pf_write_char(va_list vl, t_type *type, int *rst);
int						ft_read_iz_in(char c, char *str);
int						ft_read_atoi(char **str);

#endif
