/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write_put_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_pf_pb_rec(long long n, char *base, int len, int *rst)
{
	long long	temp;

	temp = n % len;
	if (n > len - 1)
		ft_pf_pb_rec(n / len, base, len, rst);
	ft_pf_putchar(&(base[temp]), rst);
}

void				ft_pf_write_put_base(long long n, char *base, int *rst)
{
	int			len_base;

	len_base = ft_pf_strlen(base);
	ft_pf_pb_rec(n, base, len_base, rst);
}
