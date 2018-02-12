/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:31:56 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/04 19:44:04 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*first;
	t_list	*tmp;
	t_list	*cpy;
	t_list	*new;
	int		i;

	new = ft_lstdup(lst);
	first = new;
	i = 0;
	while (new)
	{
		tmp = new;
		new = f(new);
		if (i == 0)
			first = new;
		new->next = tmp->next;
		if (i != 0)
			cpy->next = new;
		cpy = new;
		new = new->next;
		i++;
	}
	return (first);
}
