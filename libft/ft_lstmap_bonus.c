/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:50:20 by aahrach           #+#    #+#             */
/*   Updated: 2022/11/03 14:29:55 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;

	s = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
			ft_lstclear(&s, del);
		ft_lstadd_back(&s, p);
		p = p->next;
		lst = lst->next;
	}
	return (s);
}
