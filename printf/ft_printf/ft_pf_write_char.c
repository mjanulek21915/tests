/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_char(va_list vl, t_type *type)
{
	if (type->is_long == 1)
	{
		type->data.lc = (wint_t)va_arg(vl, wint_t);
		type->data_size = sizeof(wint_t);
	}
	else
		type->data.c = (char)va_arg(vl, int);
}

static void			ft_pf_write_char2(t_type *type, long long *rst)
{
	if (type->is_left)
	{
		ft_pf_putchar_s(&(type->data.c), rst, type->data_size);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		ft_pf_putchar_s(&(type->data.c), rst, type->data_size);
	}
}

void				ft_pf_write_char(va_list vl, t_type *type, long long *rst)
{
	if (type->type == 'c')
	{
		type->padding = ' ';
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		if (type->is_zero && !type->is_left)
			type->padding = '0';
		type->pad_len = type->width - 1;
		if (type->pad_len < 0)
			type->pad_len = 0;
		get_char(vl, type);
		ft_pf_write_char2(type, rst);
	}
}
