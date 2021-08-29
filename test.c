/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:16:46 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/29 22:51:54 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char *test = malloc(sizeof(char));
	int	i = 0;
	printf("%.0d\n", 0);
	ft_printf("%.0d\n", 0);
	return 0;
}
