/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:18:53 by udelorme          #+#    #+#             */
/*   Updated: 2016/01/08 14:27:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*cpy_src;
	unsigned char		*cpy_dst;
	size_t				i;
	unsigned char		ch;

	cpy_dst = dst;
	cpy_src = src;
	ch = c;
	i = -1;
	while (++i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if (cpy_src[i] == ch)
			return (&dst[i + 1]);
	}
	return (NULL);
}
