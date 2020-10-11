/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_get_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_read_get_flags(t_type *type, char **str)
{
	while (**str == '+' || **str == '-' || **str == '0' || **str == ' ' || **str == '#')
	{
		if (**str == '+')
			type->is_signed = 1;
		if (**str == '-')
			type->is_left = 1;
		if (**str == '0')
		{
			type->padding = '0';
			type->is_zero = 1;
		}
		if (**str == ' ')
			type->is_space = 1;
		if (**str == '#')
			type->is_hash = 1;
		(*str)++;
	}
}
