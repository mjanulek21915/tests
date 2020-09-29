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
		ft_pf_putchar("%", rst);
	}
}
