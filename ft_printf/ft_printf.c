/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:36:52 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/13 11:54:59 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_params(const char *str, int *con, va_list p)
{
	if (*str == 's')
		ft_putstr(va_arg(p, char *), con);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(p, int), con);
	else if (*str == 'c')
		ft_putchar(va_arg(p, int), con);
	else if (*str == 'u')
		ft_unsigned(va_arg(p, unsigned int), con);
	else if (*str == 'x')
		ft_lhex(va_arg(p, unsigned int), con);
	else if (*str == 'X')
		ft_uhex(va_arg(p, unsigned int), con);
	else if (*str == 'p')
	{
		*con += write(1, "0x", 2);
		ft_address(va_arg(p, size_t), con);
	}
	else if (*str == '%')
		*con += write(1, "%", 1);
	else
		*con += write(1, str, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		con;

	va_start(p, str);
	con = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			ft_params(str, &con, p);
		}
		else if (*str != '%')
		{
			con += write (1, str, 1);
		}
		str++;
	}
	va_end(p);
	return (con);
}
