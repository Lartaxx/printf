/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:41:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/04 19:15:31 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_ptrhex(unsigned long long n, char *base)
{
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_ptrhex(n / 16, base);
		count += ft_ptrhex(n % 16, base);
	}
	else
	{
		ft_putchar(base[n]);
		count++;
	}
	return (count);
}

int	ft_puthexa(unsigned long long n, char *base)
{
	int		count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_ptrhex(n, base);
	return (count);
}
