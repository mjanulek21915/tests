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

static void				ft_pf_write_ptr_3(t_type *type, int *rst)
{
	if (type->is_left)
	{
		if (!type->is_signed && type->is_space)
			ft_pf_putchar(" ", rst);
		if (type->is_signed)
			ft_pf_putchar(&(type->sign), rst);
		ft_pf_putstr("0x", rst);
		if (type->is_precision)
			ft_pf_write_padding(type->prec_len, '0', rst);
		ft_pf_write_put_base(type->temp, BASE_16, rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		if (!type->is_signed && type->is_space)
			ft_pf_putchar(" ", rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		if (type->is_signed)
			ft_pf_putchar(&(type->sign), rst);
		ft_pf_putstr("0x", rst);
		if (type->is_precision)
			ft_pf_write_padding(type->prec_len, '0', rst);
		ft_pf_write_put_base(type->temp, BASE_16, rst);
	}
}
static void				ft_pf_write_ptr_2(t_type *type, int *rst)
{
	type->len = ft_pf_write_nlen(type->temp, 10);
	type->prec_len = type->precision - type->len;
	type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
	type->len = type->len + ft_pf_write_get_sign(&(type->temp), type);
	type->pad_len = type->width - type->len - type->prec_len - 2;
	if (type->pad_len < 0)
		type->pad_len = 0;
	ft_pf_write_ptr_3(type, rst);
}

static void				ft_pf_write_ptr_1(t_type *type)
{
		if (type->is_left || type->is_precision == 1 || type->is_width)
			type->padding = ' ';
		if (
		(type->is_zero && type->is_precision && type->precision < 0 && type->is_width && type->width > -1 && !type->is_left))
		{
			type->precision = type->width - 2;
			if (type->is_space || type->is_signed)
				type->precision = type->precision - 1;
		}
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		if (type->is_width && type->is_zero && !type->is_precision && !type->is_left)
		{
			type->is_precision = 1;
			type->precision = type->width - 2;
			if (type->is_space || type->is_signed)
				type->precision = type->precision - 1;
		}
}

void					ft_pf_write_ptr(va_list vl, t_type *type, int *rst)
{
	if (type->type == 'p')
	{
		ft_pf_write_ptr_1(type);
		type->temp = (long)va_arg(vl, unsigned int);
		ft_pf_write_ptr_2(type, rst);
	}
}
