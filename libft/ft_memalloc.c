/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:11:47 by udelorme          #+#    #+#             */
/*   Updated: 2016/02/26 16:52:12 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *ptr_alloc;

	ptr_alloc = malloc(size);
	if (ptr_alloc)
		ft_bzero(ptr_alloc, size);
	return (ptr_alloc);
}
