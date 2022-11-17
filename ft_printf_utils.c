/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:25 by anammal           #+#    #+#             */
/*   Updated: 2022/11/17 15:46:28 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putubase(t_ul n, char *base, t_ul bl, int *counter)
{
	if (n >= bl)
	{
		ft_putubase(n / bl, base, bl, counter);
		ft_putchar(base[n % bl], counter);
	}
	else
		ft_putchar(base[n], counter);
}

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		ft_putchar('-', counter);
		ft_putchar('2', counter);
		ft_putnbr(147483648, counter);
	}
	else if (n < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(n * -1, counter);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), counter);
		ft_putchar("0123456789"[n % 10], counter);
	}
	else
		ft_putchar("0123456789"[n % 10], counter);
}

void	ft_putstr(char *s, int *counter)
{
	if (s)
		while (*s)
			ft_putchar(*s++, counter);
	else
		ft_putstr("(null)", counter);
}

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
