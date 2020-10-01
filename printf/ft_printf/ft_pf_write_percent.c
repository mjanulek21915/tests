/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_pf_write_percent(t_type *type, int *rst)
{
	if (type->type == '%')
	{
		if (type->is_width)
		{
			if (type->width < 0)
			{
				type->width = -type->width;
				type->is_left = 1;
			}
			type->pad_len = type->width - 1;
		}
		if (type->is_zero && !type->is_left)
			type->padding = ' ';
		if (type->is_left)
		{
			ft_pf_putchar("%", rst);
			ft_pf_write_padding(type->pad_len, type->padding, rst);
		}
		else
		{
			ft_pf_write_padding(type->pad_len, type->padding, rst);
			ft_pf_putchar("%", rst);
		}
	}
}
