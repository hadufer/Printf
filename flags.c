/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:49:28 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/20 02:36:29 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_handler(const char *fmt, size_t *i, t_printf *pf)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '-')
			pf->ladjust = true;
		else if (fmt[*i] == '+')
			pf->plus_sign = '+';
		else if (fmt[*i] == '#')
			pf->altfmt = true;
		else if (fmt[*i] == '0')
			pf->padc = '0';
		else if (fmt[*i] == ' ')
		{
			if (pf->plus_sign == 0)
				pf->plus_sign = ' ';
		}
		else
			return (0);
		(*i)++;
	}
	return (-1);
}

int	width_handler(const char *fmt, size_t *i, t_printf *pf)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '*')
		{
			pf->width_arg = true;
			(*i)++;
			return (0);
		}
		else
		{
			while (fmt[*i] && ft_isdigit(fmt[*i]))
			{
				pf->length = 10 * pf->length + (fmt[*i] - '0');
				(*i)++;
			}
			return (0);
		}
	}
	return (-1);
}

int	precision_handler(const char *fmt, size_t *i, t_printf *pf)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '*')
		{
			pf->prec_arg = true;
			(*i)++;
			return (0);
		}
		else
		{
			if (ft_isdigit(fmt[*i]))
			{
				pf->prec = 0;
				while (fmt[*i] && ft_isdigit(fmt[*i]))
				{
					pf->prec = 10 * pf->prec + (fmt[*i] - '0');
					(*i)++;
				}
			return (0);
			}
		}
		(*i)++;
	}
	return (-1);
}

int	specifier_handler(const char *fmt, size_t *i, t_printf *pf, va_list va_list)
{
	if (fmt[*i] == 'c')
		ft_putchar_fd(va_arg(va_list, int), 1);
	else if (fmt[*i] == 's')
		ft_putstr_fd(va_arg(va_list, char *), 1);
	else if (fmt[*i] == 'u')
		print_unsigned(va_arg(va_list, unsigned int), 10, pf);
	else if (fmt[*i] == 'p' || fmt[*i] == 'x')
	{
		if (fmt[*i] == 'p')
			pf->prefix = "0x";
		print_unsigned(va_arg(va_list, unsigned long), 16, pf);
	}
	else if (fmt[*i] == 'i' || fmt[*i] == 'd')
		print_signed((long)va_arg(va_list, int), 10, pf);
	else if (fmt[*i] == '%')
		ft_putchar_fd('%', 1);
	else
		return (-1);
	(*i)++;

}
