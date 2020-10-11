/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *str, ...)
{
	va_list			va;
	char			*temp;
	long long		rst;

	if (!str)
		return (0);
	temp = (char *)str;
	if (!temp)
		return (0);
	va_start(va, str);
	rst = 0;
	while (*temp)
	{
		if (*temp == '%')
			ft_read(&temp, va, &rst);
		else if (*temp)
			ft_pf_putchar(temp, &rst);
		temp++;
	}
	return (rst);
}
