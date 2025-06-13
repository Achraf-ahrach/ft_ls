/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:32:36 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/04 19:19:55 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = f(j, s[j]);
		j++;
	}
	p[j] = '\0';
	return (p);
}
