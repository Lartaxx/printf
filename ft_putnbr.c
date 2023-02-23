/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:22:09 by daboyer           #+#    #+#             */
/*   Updated: 2023/02/22 13:23:23 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(int n)
{
	int	i;
	int	number[10];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putstr("2147483648");
			return ;
		}
		n = -n;
	}
	while (n > 0)
	{
		number[i++] = n % 10;
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar(('0' + number[i]));
}
