/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_get_sign_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_pf_write_get_sign_s(t_type *type)
{
	type->sign = 0;
	if (type->data.temp < 0)
	{
		type->sign = '-';
		type->is_neg = 1;
		type->data.u_temp = ~type->data.u_temp + 1;
		return (1);
	}
	else if (type->is_signed)
	{
		type->sign = '+';
		return (0);
	}
	else if (type->is_space)
	{
		type->sign = 0;
		return (0);
	}
	type->sign = 0;
	return (0);
}
