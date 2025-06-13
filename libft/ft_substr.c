/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:03:23 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/04 17:34:39 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		p[j++] = s[start++];
		i--;
	}
	p[j] = '\0';
	return (p);
}
