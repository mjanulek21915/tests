/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_n_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_pf_write_n_s(void *ptr, int n, long long *rst, int size)
{
	char	*str;

	str = (char *)ptr;
	if (!str)
		return ;
	if (n == -1)
	{
		while (*str)
		{
			ft_pf_putchar_s(str, rst, size);
			str = str + size;
		}
	}
	else
	{
		while (n--)
		{
			ft_pf_putchar_s(str, rst, size);
			str = str + size;
		}
	}
}
