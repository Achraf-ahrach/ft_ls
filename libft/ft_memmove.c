/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:58:06 by aahrach           #+#    #+#             */
/*   Updated: 2022/10/28 20:22:12 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len )
{
	size_t	i;
	char	*ds;
	char	*sr;

	i = 0;
	if (!dest && !src)
		return (dest);
	ds = (char *)dest;
	sr = (char *)src;
	if (dest > src)
	{
		while (len - i > 0)
		{
			ds[len - i - 1] = sr[len - i - 1];
			i++;
		}
	}
	while (i < len)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dest);
}
