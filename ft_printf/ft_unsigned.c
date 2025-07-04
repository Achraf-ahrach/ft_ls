/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:18:31 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/09 20:56:24 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int nb, int *con)
{
	if (nb <= 9)
	{
		ft_putchar((nb + 48), con);
	}
	else if (nb > 9)
	{
		ft_unsigned((nb / 10), con);
		ft_unsigned((nb % 10), con);
	}
}
