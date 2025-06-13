/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:07:43 by aahrach           #+#    #+#             */
/*   Updated: 2022/10/27 15:40:29 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*c;

	s = (unsigned char *)s1;
	c = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s[i] != c[i])
			return (s[i] - c[i]);
		i++;
	}
	return (0);
}
