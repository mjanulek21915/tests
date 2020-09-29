/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_read_atoi(char **str)
{
	int rst;

	rst = -2;
	if (**str == '*')
	{
		(*str)++;
		return (-1);
	}
	if (**str >= '0' && **str <= '9')
		rst = 0;
	while (**str >= '0' && **str <= '9')
	{
		rst = rst * 10;
		rst = rst + **str - '0';
		(*str)++;
		if (rst < 0)
			return (0);
	}
	return (rst);
}