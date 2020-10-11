/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_pf_write_ptr_3(t_type *type, long long *rst)
{
	if (type->is_left)
	{
		ft_pf_putstr("0x", rst);
		if (type->is_precision)
			ft_pf_write_padding(type->prec_len, '0', rst);
		if (!type->print_none)
			ft_pf_write_put_base(type->temp, BASE_16, rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		ft_pf_putstr("0x", rst);
		if (type->is_precision)
			ft_pf_write_padding(type->prec_len, '0', rst);
		if (!type->print_none)
			ft_pf_write_put_base(type->temp, BASE_16, rst);
	}
}

static void			ft_pf_write_ptr_2(t_type *type, long long *rst)
{
	type->len = ft_pf_write_nlen(type->temp, 16);
	type->prec_len = type->precision - type->len;
	type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
	type->len = type->len;
	if (type->print_none)
		type->len = 0;
	type->pad_len = type->width - type->len - type->prec_len - 2;
	if (type->pad_len < 0)
		type->pad_len = 0;
	ft_pf_write_ptr_3(type, rst);
}

static void			ft_pf_write_ptr_1(t_type *type)
{
	if (type->is_left || type->is_precision == 1 || type->is_width)
		type->padding = ' ';
	if (type->is_zero && type->is_precision && type->precision < 0 &&
	type->is_width && type->width > -1 && !type->is_left)
		type->precision = type->width - 2;
	if (type->width < 0)
	{
		type->width = -type->width;
		type->is_left = 1;
	}
	if (type->is_width && type->is_zero && !type->is_precision
	&& !type->is_left)
	{
		type->is_precision = 1;
		type->precision = type->width - 2;
	}
}

void				ft_pf_write_ptr(va_list vl, t_type *type, long long *rst)
{
	if (type->type == 'p')
	{
		type->temp = (unsigned long long)va_arg(vl, unsigned long long);
		if (type->is_precision && type->precision == 0 && type->temp == 0)
			type->print_none = 1;
		ft_pf_write_ptr_1(type);
		ft_pf_write_ptr_2(type, rst);
	}
}
