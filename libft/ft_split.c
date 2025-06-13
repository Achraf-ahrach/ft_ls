/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:00:36 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/04 18:58:57 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			if (s[i] == c || s[i] == '\0')
				j++;
		}
	}
	return (j);
}

static int	ft_hseb(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	*ft_free_all(char **p, int a)
{
	while (a >= 0)
	{
		free(p[a]);
		a--;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		a;
	int		j;

	a = 0;
	if (!s)
		return (NULL);
	j = ft_check(s, c);
	p = malloc((j + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (a < j)
	{
		while (*s == c && *s)
			s++;
		p[a] = ft_substr(s, 0, ft_hseb(s, c));
		if (!p[a])
			return (ft_free_all(p, a));
		while (*s != c && *s != '\0')
			s++;
		a++;
	}
	p[a] = NULL;
	return (p);
}
