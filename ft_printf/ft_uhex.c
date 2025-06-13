/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:56:57 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/09 20:54:41 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uhex(unsigned int nb, int *con)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_uhex((nb / 16), con);
		ft_uhex((nb % 16), con);
	}
	else
	{
		ft_putchar(str[nb], con);
	}
}
