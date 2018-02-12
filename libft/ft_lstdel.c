/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:56:13 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/02 14:19:51 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *index;
	t_list *index2;

	index = *alst;
	index2 = *alst;
	while (index)
	{
		index2 = index;
		index = index->next;
		ft_lstdelone(&index2, del);
	}
	*alst = NULL;
}
