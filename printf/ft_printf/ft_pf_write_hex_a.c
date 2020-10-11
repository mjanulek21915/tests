/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_hex_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_temp_hex_a(va_list vl, t_type *type)
{
	if (type->is_long == 1)
		type->data.u_temp = (unsigned long)va_arg(vl, unsigned long);
	else if (type->is_long == 2)
		type->data.u_temp = (unsigned long long)va_arg(vl, unsigned long long);
	else if (type->is_short == 1)
		type->data.u_temp = (unsigned short)va_arg(vl, unsigned int);
	else if (type->is_short == 2)
		type->data.u_temp = (unsigned char)va_arg(vl, unsigned int);
	else
		type->data.u_temp = (unsigned int)va_arg(vl, unsigned int);
	if (type->data.u_temp == 0)
		type->is_hash = 0;
}

static void			ft_pf_write_hex_a_2(t_type *type, long long *rst)
{
	if (type->print_none)
		type->len = 0;
	type->prec_len = type->precision - type->len;
	type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
	type->pad_len = type->width - type->len - type->prec_len;
	if (type->is_hash)
		type->pad_len = type->pad_len - 2;
	if (type->is_left)
	{
		if (type->is_hash)
			write(1, "0x", 2);
		ft_pf_write_padding(type->prec_len, '0', rst);
		if (!type->print_none)
			ft_pf_write_put_base(type->data.u_temp, BASE_16A, rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		if (type->is_hash)
			write(1, "0x", 2);
		ft_pf_write_padding(type->prec_len, '0', rst);
		if (!type->print_none)
			ft_pf_write_put_base(type->data.u_temp, BASE_16A, rst);
	}
}

void				ft_pf_write_hex_a(va_list vl, t_type *type, long long *rst)
{
	if (type->type == 'X')
	{
		get_temp_hex_a(vl, type);
		if (type->is_precision && !type->precision && !type->data.u_temp)
			type->print_none = 1;
		if (type->is_left || type->is_precision == 1 || type->is_width)
			type->padding = ' ';
		if (type->is_width && !type->is_precision && type->is_zero
		&& !type->is_left)
		{
			type->precision = type->width;
			type->is_precision = 1;
		}
		else if (type->is_width && type->width > 0 && type->is_precision
		&& type->is_zero && type->precision < 0 && !type->is_left)
			type->precision = type->width;
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		type->len = ft_pf_write_nlen(type->data.u_temp, 16);
		ft_pf_write_hex_a_2(type, rst);
	}
}
