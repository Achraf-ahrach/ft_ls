/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:07:44 by aahrach           #+#    #+#             */
/*   Updated: 2022/10/28 17:17:41 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_check(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_cpy(const char *p, const char *s1, int lens1, int i)
{
	int	j;

	j = 0;
	while (i <= lens1)
	{
		((char *)p)[j] = ((char *)s1)[i];
		j++;
		i++;
	}
	((char *)p)[j] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		lens1;
	int		i;
	char	*p;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_check(set, s1[i]) == 1)
		i++;
	lens1 = ft_strlen(s1);
	lens1--;
	while (lens1 >= i && ft_check(set, s1[lens1]) == 1)
		lens1--;
	p = malloc((lens1 - i + 2) * sizeof(char));
	if (!p)
		return (NULL);
	ft_cpy(p, s1, lens1, i);
	return (p);
}
