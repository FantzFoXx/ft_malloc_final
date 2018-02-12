/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:40:53 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/03 21:08:21 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cpy_src;
	const unsigned char	*ptr_src;
	unsigned char		*cpy_dst;
	size_t				i;

	i = -1;
	cpy_dst = dst;
	ptr_src = src;
	cpy_src = (unsigned char *)malloc(sizeof(unsigned char) * len);
	while (++i < len)
		cpy_src[i] = ptr_src[i];
	i = -1;
	while (++i < len)
		cpy_dst[i] = cpy_src[i];
	free(cpy_src);
	return (dst);
}
