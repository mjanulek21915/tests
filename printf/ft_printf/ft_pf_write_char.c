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

static void				ft_pf_write_char2(char temp, t_type *type, int *rst)
{
	if (type->is_left)
	{
		ft_pf_putchar(&temp, rst);
		ft_pf_write_padding(type->pad_len, type->padding, rst);
	}
	else
	{
		ft_pf_write_padding(type->pad_len, type->padding, rst);
		ft_pf_putchar(&temp, rst);
	}
}
void					ft_pf_write_char(va_list vl, t_type *type, int *rst)
{
	char	temp;

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
		temp = (char)va_arg(vl, int);
		ft_pf_write_char2(temp, type, rst);
	}
}
