/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_uint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_pf_write_uint_2(t_type *type, int *rst)
{
	type->len = ft_pf_write_nlen(type->temp, 10);
	type->prec_len = type->precision - type->len;
	type->prec_len = (type->prec_len > 0) ? type->prec_len : 0;
	type->pad_len = type->width - type->len - type->prec_len;
	if (type->pad_len < 0)
		type->pad_len = 0;
	if (type->is_left)
	{
		ft_pf_write_padding(type->prec_len, '0', rst);
		ft_pf_write_put_base(type->temp, BASE_10, rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		ft_pf_write_padding(type->prec_len, '0', rst);
		ft_pf_write_put_base(type->temp, BASE_10, rst);
	}
}

void					ft_pf_write_uint(va_list vl, t_type *type, int *rst)
{
	if (type->type == 'u')
	{
		type->temp = (unsigned int)va_arg(vl, int);
		if (type->is_precision && type->precision == 0 && type->temp == 0)
			return ;
		if (type->is_left || type->is_precision == 1 || type->is_width)
			type->padding = ' ';
		if (type->is_width && !type->is_precision && type->is_zero == 1
		&& !type->is_left)
		{
			type->precision = type->width;
			type->is_precision = 1;
		}
		else if (type->is_width && type->width > 0 && type->is_precision &&
		type->is_zero == 1 && type->precision < 0 && !type->is_left)
			type->precision = type->width;
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		ft_pf_write_uint_2(type, rst);
	}
}
