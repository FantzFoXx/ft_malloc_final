/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:28:34 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/04 19:41:23 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*dup;
	t_list	*tmp;
	int		i;

	dup = NULL;
	tmp = NULL;
	i = 0;
	while (lst)
	{
		if (i == 0)
		{
			dup = ft_lstnew(lst->content, lst->content_size);
			tmp = dup;
		}
		else
			ft_lstpush(&dup, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
		i++;
	}
	return (tmp);
}
