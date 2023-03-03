/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:01:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/01 13:56:10 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_readtext(const char *str)
{
	while (*str && *str != '%')
	{
		ft_putchar(*str);
		str++;
	}
	return ((char *)str);
}

// Count the length of an integer
static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_search_args(const char *str, va_list list)
{
	char	*format;

	if (*str == 'c')
		ft_putchar((char)va_arg(list, int));
	else if (*str == 's')
		ft_putstr(va_arg(list, char *));
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(list, int));
	else if (*str == 'u')
		ft_putnbr_u((unsigned int)va_arg(list, unsigned int));
	else if (*str == 'x')
		ft_putnbr_base(va_arg(list, int), "0123456789abcdef");
	else if (*str == 'X')
		ft_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
	else if (*str == 'p')
	{
		format = "0123456789abcdef";
		ft_puthexa((unsigned long long)va_arg(list, void *), format);
	}
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
		else
			str = ft_readtext(str);
		if (!str)
		{
			va_end(list);
			return (0);
		}
	}
	va_end(list);
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	a = 'a';	
// 	ft_printf("%p", &a);
// 	printf("\n%p", &a);
// }