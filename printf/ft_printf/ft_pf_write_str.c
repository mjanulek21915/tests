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

static void				ft_pf_write_str_2(t_type *type int *rst)
{
		if (type->is_left)
		{
			ft_pf_write_n(type->ptr_temp, type->len, rst);
			ft_pf_write_padding(type->pad_len, ' ', rst);
		}
		else
		{
			ft_pf_write_padding(type->pad_len, ' ', rst);
			ft_pf_write_n(type->ptr_temp, type->len, rst);
		}
}

void					ft_pf_write_str(va_list vl, t_type *type, int *rst)
{
	if (type->type == 's')
	{
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		type->ptr_temp = va_arg(vl, char *);
		if (!type->ptr_temp)
			return ;
		type->len = ft_pf_strlen(type->ptr_temp);
		if (type->is_precision)
			if (type->precision >= 0 && type->precision < type->len)
				type->len = type->precision;
		type->pad_len = type->width - type->len;
		if (type->pad_len < 0)
			type->pad_len = 0;
	}
}