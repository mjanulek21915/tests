/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_strlen_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			strlen_wchar(void *ptr)
{
	int			i;
	wchar_t		*str;

	str = (wchar_t *)ptr;
	i = 0;
	while (*str++)
		i++;
	return (i);
}

static int			strlen_char(void *ptr)
{
	int			i;
	char		*str;

	str = (char *)ptr;
	i = 0;
	while (*str++)
		i++;
	return (i);
}

int					ft_pf_strlen_s(void *ptr, int mode)
{
	if (!ptr)
		return (0);
	if (mode == 1)
		return (strlen_wchar(ptr));
	else
		return (strlen_char(ptr));
}
