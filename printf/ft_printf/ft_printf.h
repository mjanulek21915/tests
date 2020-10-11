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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

# define CONV "cspdiuxXn%"
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16A "0123456789ABCDEF"

# define TEST "cesi est un test"

typedef union			u_data
{
	long long			temp;
	unsigned long long	u_temp;
	long long			ll;
	unsigned long long	ull;
	void				*ptr;
	wint_t				lc;
	char				c;
}						t_data;

typedef union			u_ptr
{
	void				*ptr;
	int					*i;
	long				*l;
	long long			*ll;
	short				*h;
	char				*hh;
}						t_ptr;

typedef struct			s_type
{
	long long			temp;
	char				*ptr_temp;
	void				*ptr;
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
	int					is_neg;
	int					is_neg_prec;
	int					is_changed;
	int					is_long;
	int					is_short;
	int					is_hash;
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
	t_data				data;
	int					data_size;
}						t_type;

void					ft_pf_putchar_s(void *ptr, long long *rst, int size);
int						ft_printf(const char *str, ...);
void					ft_read(char **str, va_list va, long long *rst);
void					ft_read_get_length(t_type *type, char **str);
int						ft_pf_write_get_sign_s(t_type *type);
int						ft_pf_strlen(char *str);
int						ft_pf_strlen_s(void *str, int mode);
void					ft_write(t_type *type, va_list va, long long *rst);
void					ft_pf_putchar(char *ptr, long long *rst);
void					ft_pf_putstr(char *str, long long *rst);
int						ft_pf_write_get_sign(long long *temp, t_type *type);
int						ft_pf_write_nlen(unsigned long long n, int base);
void					ft_pf_write_n_s(void *ptr, int n, long long *rst,
int size);
void					ft_pf_write_n(char *str, int n, long long *rst);
void					ft_pf_write_uint(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_str(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_put_base(unsigned long long n,
char *base, long long *rst);
void					ft_pf_write_ptr(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_percent(t_type *type, long long *rst);
void					ft_pf_write_padding(int n, char c,
long long *rst);
void					ft_pf_write_int(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_hex(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_hex_a(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_char(va_list vl, t_type *type,
long long *rst);
void					ft_pf_write_to_ptr(va_list vl, t_type *type,
long long *rst);
int						ft_read_iz_in(char c, char *str);
int						ft_read_atoi(char **str);
void					ft_read_get_flags(t_type *type, char **str);

#endif
