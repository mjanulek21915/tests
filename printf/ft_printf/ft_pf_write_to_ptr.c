/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_to_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_pf_write_to_ptr(va_list vl, t_type *type, long long *rst)
{
	t_ptr temp;

	if (type->type == 'n')
	{
		temp.ptr = (int *)va_arg(vl, int *);
		if (type->is_long == 1)
			*(temp.l) = (long)(*rst);
		else if (type->is_long == 2)
			*(temp.ll) = (long long)(*rst);
		else if (type->is_short == 1)
			*(temp.h) = (short)(*rst);
		else if (type->is_short == 2)
			*(temp.hh) = (char)(*rst);
		else
			*(temp.i) = (int)(*rst);
	}
}
