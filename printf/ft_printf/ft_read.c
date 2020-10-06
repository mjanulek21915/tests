/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					get_nums_1(t_type *type, char **str, va_list vl)
{
	int			temp;

	if (**str == '.')
	{
		(*str)++;
		temp = ft_read_atoi(str);
		if (temp > -2)
		{
			type->is_precision = 1;
			if (temp == -1)
			{
				type->precision = va_arg(vl, int);
				type->prec_star = 1;
			}
			else
				type->precision = temp;
		}
	}
}

static void					get_nums(t_type *type, char **str, va_list vl)
{
	int			temp;

	temp = ft_read_atoi(str);
	if (temp > -2)
	{
		type->is_width = 1;
		if (temp == -1)
		{
			type->width_star = 1;
			type->width = va_arg(vl, int);
		}
		else
			type->width = temp;
	}
	get_nums_1(type, str, vl);
}

static void					get_flags(t_type *type, char **str)
{
	while (**str == '+' || **str == '-' || **str == '0' || **str == ' ')
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
		(*str)++;
	}
}

static void					ft_read_init(t_type *type)
{
	type->is_percent = 0;
	type->is_left = 0;
	type->is_signed = 0;
	type->is_space = 0;
	type->is_width = 0;
	type->is_precision = 0;
	type->is_zero = 0;
	type->is_star = 0;
	type->is_prec_orig = 0;
	type->is_width_orig = 0;
	type->print_none = 0;
	type->width_star = 0;
	type->prec_star = 0;
	type->padding = ' ';
	type->width = 0;
	type->precision = 0;
	type->type = 0;
	type->sign = 0;
	type->len = 0;
	type->prec_len = 0;
	type->pad_len = 0;
	type->temp = 0;
	type->ptr_temp = 0;
	type->ptr = 0;
}

void						ft_read(char **str, va_list vl, int *rst)
{
	t_type		type;
	char		*temp;

	temp = *str;
	temp++;
	ft_read_init(&type);
	get_flags(&type, &temp);
	get_nums(&type, &temp, vl);
	if (!(ft_read_iz_in(*temp, CONV)))
		return ;
	type.type = *temp;
	*str = temp;
	ft_write(&type, vl, rst);
}
