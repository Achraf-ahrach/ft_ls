/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:51:49 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/08 14:14:05 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *con)
{
	if (nb == -2147483648)
	{
		*con += write (1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		*con += write (1, "-", 1);
		ft_putnbr((nb * -1), con);
	}
	else if (nb <= 9 && nb >= 0)
	{
		ft_putchar((nb + 48), con);
	}
	else if (nb > 9)
	{
		ft_putnbr((nb / 10), con);
		ft_putnbr((nb % 10), con);
	}
}
