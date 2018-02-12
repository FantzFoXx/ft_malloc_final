/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:18:03 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/03 21:28:52 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*cpy_src;
	unsigned char		*cpy_dst;
	size_t				i;

	cpy_dst = (unsigned char *)dst;
	cpy_src = (const unsigned char *)src;
	i = -1;
	while (++i < n)
		cpy_dst[i] = cpy_src[i];
	return (dst);
}
