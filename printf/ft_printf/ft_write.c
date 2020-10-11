/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_write(t_type *type, va_list vl, long long *rst)
{
	if ((type->is_long && type->is_short) ||
	(type->is_long > 2 || type->is_short > 2))
		return ;
	ft_pf_write_str(vl, type, rst);
	ft_pf_write_hex(vl, type, rst);
	ft_pf_write_ptr(vl, type, rst);
	ft_pf_write_hex_a(vl, type, rst);
	ft_pf_write_int(vl, type, rst);
	ft_pf_write_uint(vl, type, rst);
	ft_pf_write_percent(type, rst);
	ft_pf_write_char(vl, type, rst);
	ft_pf_write_to_ptr(vl, type, rst);
}
