/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:05:25 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/03 14:19:50 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nomber(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		j;
	long	nb;

	nb = n;
	j = 0;
	i = ft_nomber(nb);
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (nb < 0)
	{
		j++;
		p[0] = '-';
		nb *= -1;
	}
	p[i--] = '\0';
	while (i >= j)
	{
		p[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (p);
}
