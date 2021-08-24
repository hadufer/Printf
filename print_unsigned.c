/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:49:49 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/16 17:09:07 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_length(unsigned long nb, int base)
{
	int	count;

	count = 1;
	nb /= base;
	if (nb)
	{
		count++;
		nb /= base;
		while (nb)
		{
			nb /= base;
			count++;
		}
	}
	return (count);
}

void	print_unsigned(unsigned long nb, int base, t_printf *pf)
{
	const char	char_list[] = "0123456789abcdef0123456789ABCDEF";
	char		ret[14];
	int			i;
	int			length;

	i = uint_length(nb, base);
	ret[i--] = 0;
	ret[i--] = char_list[(nb % base) + pf->capitals];
	nb /= base;
	while (nb)
	{
		ret[i--] = char_list[(nb % base) + pf->capitals];
		nb /= base;
	}
	if (pf->plus_sign == '+')
		ft_putchar_fd('+', 1);
}


