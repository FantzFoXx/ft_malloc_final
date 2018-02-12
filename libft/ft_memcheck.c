/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:13:12 by udelorme          #+#    #+#             */
/*   Updated: 2017/03/30 13:29:14 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcheck(const void *m, int c, size_t size)
{
	size_t		i;
	const char	*addr;

	addr = (const char *)m;
	i = 0;
	while (i < size)
	{
		if (addr[i] != c)
			return (0);
		i++;
	}
	return (1);
}
