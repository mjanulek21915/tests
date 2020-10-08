/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_pf_write_int_3(t_type *type, int *rst)
{
	if (!type->is_neg && type->is_space && !type->is_signed)
		ft_pf_putchar(" ", rst);
	if (type->is_left)
	{
		if (type->sign)
			ft_pf_putchar(&(type->sign), rst);
		if (type->is_precision)
			ft_pf_write_padding(type->prec_len, '0', rst);
		if (!type->print_none)
			ft_pf_write_put_base(type->temp, BASE_10, rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		if (type->sign)
			ft_pf_putchar(&(type->sign), rst);
		ft_pf_write_padding(type->prec_len, '0', rst);
		if (!type->print_none)
			ft_pf_write_put_base(type->temp, BASE_10, rst);
	}
}

static void				ft_pf_write_int_2(t_type *type, int *rst)
{
	if ((type->temp < 0 && !type->is_zero) ||
	(type->temp < 0 && type->is_prec_orig))
		type->precision = type->precision + 1;
	type->len = ft_pf_write_get_sign(&(type->temp), type) +
	ft_pf_write_nlen(type->temp, 10);
	if (type->print_none)
		type->len = 0;
	type->prec_len = type->precision - type->len;
	type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
	type->pad_len = type->width - type->len - type->prec_len;
	if ((type->is_space || type->is_signed) && !type->is_neg)
		type->pad_len = type->pad_len - 1;
	if ((((type->is_width_orig && !type->is_prec_orig && type->is_zero
	&& type->is_space)
	|| (type->is_width && type->is_zero && type->is_signed
	&& !type->is_prec_orig)))
	&& !type->is_neg)
		type->prec_len = type->prec_len - 1;
	if (type->pad_len < 0)
		type->pad_len = 0;
	ft_pf_write_int_3(type, rst);
}

void					ft_pf_write_int_1(t_type *type)
{
	if (type->precision > -1 && type->is_precision)
		type->is_prec_orig = 1;
	if (type->precision < 0 && type->is_precision)
		type->is_neg_prec = 1;
	if (type->width > -1 && type->is_width)
		type->is_width_orig = 1;
	if (type->is_precision && type->precision == 0 && type->temp == 0)
		type->print_none = 1;
	if (type->is_left || type->is_precision || type->is_width)
		type->padding = ' ';
	if (type->is_width && !type->is_precision
	&& type->is_zero && !type->is_left)
	{
		type->precision = type->width;
		type->is_precision = 1;
	}
	else if (type->is_width && type->width > 0 && type->is_precision
	&& type->is_zero && type->precision < 0 && !type->is_left)
	{
		type->is_changed = 1;
		type->precision = type->width;
	}
}

void					ft_pf_write_int(va_list vl, t_type *type, int *rst)
{
	if (type->type == 'd' || type->type == 'i')
	{
		type->temp = (int)va_arg(vl, int);
		ft_pf_write_int_1(type);
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		ft_pf_write_int_2(type, rst);
	}
}
