/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:41:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/01 13:57:15 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_ptrhex(unsigned long long n, char *base)
{
	if (n >= 16)
	{
		ft_ptrhex(n / 16, base);
		ft_ptrhex(n % 16, base);
	}
	else
		ft_putchar(base[n]);
}

void	ft_puthexa(unsigned long long n, char *base)
{
	ft_putstr("0x");
	ft_ptrhex(n, base);
}
