/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:57 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/04 19:24:27 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
