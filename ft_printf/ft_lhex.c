/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:03:59 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/09 20:52:27 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lhex(unsigned int nb, int *con)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_lhex((nb / 16), con);
		ft_lhex((nb % 16), con);
	}
	else
	{
		ft_putchar(str[nb], con);
	}
}
