/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:31:35 by aahrach           #+#    #+#             */
/*   Updated: 2022/10/26 19:37:27 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (lensrc);
	lendst = ft_strlen(dst);
	if (dstsize <= lendst)
		return (dstsize + lensrc);
	while (src[i] && lendst + i + 1 < dstsize)
	{
		dst[i + lendst] = src[i];
		i++;
	}
	dst[i + lendst] = '\0';
	return (lendst + lensrc);
}
