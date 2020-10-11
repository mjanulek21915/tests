/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_str(va_list vl, t_type *type)
{
	if (type->is_long == 1)
	{
		type->data.ptr = (void *)va_arg(vl, wchar_t *);
		type->data_size = sizeof(wchar_t);
	}
	else
		type->data.ptr = (void *)va_arg(vl, char *);
}

static void			ft_pf_write_str_2(t_type *type, long long *rst)
{
	if (type->is_left)
	{
		ft_pf_write_n_s(type->data.ptr, type->len, rst, type->data_size);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		ft_pf_write_n_s(type->data.ptr, type->len, rst, type->data_size);
	}
}

void				ft_pf_write_str(va_list vl, t_type *type, long long *rst)
{
	if (type->type == 's')
	{
		type->padding = ' ';
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		if (type->is_zero && !type->is_left)
			type->padding = '0';
		get_str(vl, type);
		if (!type->data.ptr)
			type->data.ptr = "(null)";
		type->len = ft_pf_strlen_s(type->data.ptr,
		(type->is_long == 1 ? 1 : 0));
		if (type->is_precision)
			if (type->precision >= 0 && type->precision < type->len)
				type->len = type->precision;
		type->pad_len = type->width - type->len;
		if (type->pad_len < 0)
			type->pad_len = 0;
		ft_pf_write_str_2(type, rst);
	}
}
