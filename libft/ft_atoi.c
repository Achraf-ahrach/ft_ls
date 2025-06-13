/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:08:32 by aahrach           #+#    #+#             */
/*   Updated: 2022/10/29 11:02:10 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	x = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		x = x - 2;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
			nbr = (nbr * 10) + (str[i] - 48);
			i++;
	}
	return (nbr * x);
}
