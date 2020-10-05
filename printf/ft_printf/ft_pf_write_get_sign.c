/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_get_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pf_write_get_sign(long long *temp, t_type *type)
{
	type->sign = 0;
	if (*temp < 0)
	{
		type->sign = '-';
		*temp = -*temp;
		return (1);
	}
	else if (type->is_signed)
	{
		type->sign = '+';
		return (1);
	}
	else if (type->is_space)
	{
		type->sign = 0;
		if (type->is_precision)
			return (0);
		return (1);
	}
	type->sign = 0;
	return (0);
}
