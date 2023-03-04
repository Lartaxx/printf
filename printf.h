/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:07:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/04 19:26:35 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);

int		ft_putstr(const char *str);

int		ft_putnbr(int n);

int		ft_putnbr_u(unsigned int n);

int		ft_putnbr_base(int nbr, char *base);

int		ft_puthexa(unsigned long long n, char *base);
#endif
