/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:01:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/02/22 13:46:28 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_search_args(const char *str, va_list list)
{
	if (*str == 'c')
	       ft_putchar((char)va_arg(list, int));
	else if (*str == 's')
		ft_putstr(va_arg(list, char *));
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(list, int));
	else if (*str == 'u')
		ft_putnbr_u((unsigned int)va_arg(list, unsigned int));
	else if (*str == '%')
		ft_putchar('%');
	else
		return (NULL);
	str++;
	return ((char *)str);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	va_start(list, str);

	while (*str)
	{
		if (*str == '%')
			str = ft_search_args(str + 1, list);
		if (!str)
		{
			va_end(list);
			return (0);
		}
	}
	va_end(list);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("%d%s", 5, "mounas la pute");
	printf("\n %d %s", -33, "mounas la folle");
}
