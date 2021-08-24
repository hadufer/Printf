/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:16:46 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/24 21:22:10 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char *test = malloc(sizeof(char));
	int	i = 0;
	printf("%0 2s\n", "s");
	ft_printf("%0 2s\n", "s");
	return 0;
}
