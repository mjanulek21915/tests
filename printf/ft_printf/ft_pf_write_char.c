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

void					ft_pf_write_char(va_list vl, t_type *type, int *rst)
{
	char	temp;
	int		p_len;

	if (type->type == 'c')
	{
		if (type->width < 0)
		{
			type->width = -type->width;
			type->is_left = 1;
		}
		p_len = type->width - 1;
		if (p_len < 0)
			p_len = 0;
		temp = (char)va_arg(vl, int);
		if (type->is_left)
		{
			ft_pf_putchar(&temp, rst);
			ft_pf_write_padding(p_len, ' ', rst);
		}
		else
		{
			ft_pf_write_padding(p_len, ' ', rst);
			ft_pf_putchar(&temp, rst);
		}
	}
}
