/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:52:23 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/09 18:58:37 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_address(size_t nb, int *con)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb < 16)
	{
		*con += write (1, &str[nb], 1);
	}
	else
	{
		ft_address(nb / 16, con);
		ft_address(nb % 16, con);
	}
}
