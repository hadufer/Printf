/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:16:46 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/24 12:22:56 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char *test = malloc(sizeof(char));
	int	i = 0;
	printf("%0 -10df\n", 123);
	ft_printf("%0 -10df\n", 123);
	// Cas d'erreur
	return 0;
}
