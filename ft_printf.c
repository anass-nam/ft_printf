/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:12 by anammal           #+#    #+#             */
/*   Updated: 2022/11/17 15:46:19 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_converter(va_list a, char c, int *counter);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	if (format)
	{
		va_start(args, format);
		i = 0;
		counter = 0;
		while (*(format + i))
		{
			if (*(format + i) == '%')
				ft_converter(args, *(format + (++i)), &counter);
			else
				ft_putchar(*(format + i), &counter);
			i++;
		}
		va_end(args);
		return (counter);
	}
	return (-1);
}

static void	ft_converter(va_list a, char c, int *counter)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(a, int), counter);
	else if (c == 's')
		ft_putstr((char *)va_arg(a, void *), counter);
	else if (c == 'x')
		ft_putubase(va_arg(a, unsigned int), "0123456789abcdef", 16, counter);
	else if (c == 'X')
		ft_putubase(va_arg(a, unsigned int), "0123456789ABCDEF", 16, counter);
	else if (c == 'u')
		ft_putubase(va_arg(a, unsigned int), "0123456789", 10, counter);
	else if (c == 'p')
	{
		ft_putstr("0x", counter);
		ft_putubase((t_ul)va_arg(a, void *), "0123456789abcdef", 16, counter);
	}
	else if (c == 'c')
		ft_putchar(va_arg(a, int), counter);
	else
		ft_putchar(c, counter);
}
