/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:35 by anammal           #+#    #+#             */
/*   Updated: 2022/11/17 15:46:39 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define LHBASE "0123456789abcdef"
# define UHBASE "0123456789ABCDEF"
# define DBASE "0123456789"

typedef unsigned long	t_ul;
typedef unsigned int	t_ui;

int		ft_printf(const char *format, ...);
void	ft_putubase(t_ul n, char *base, t_ul bl, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putchar(char c, int *counter);

#endif