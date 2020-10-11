/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_pf_write_n(char *str, int n, long long *rst)
{
	if (!str)
		return ;
	if (n == -1)
	{
		while (*str)
		{
			ft_pf_putchar(str, rst);
			str++;
		}
	}
	else
	{
		while (n-- && *str)
		{
			ft_pf_putchar(str, rst);
			str++;
		}
	}
}
