/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:23:29 by udelorme          #+#    #+#             */
/*   Updated: 2015/11/29 19:57:10 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		i;
	size_t		dst_len;

	d = dst;
	s = src;
	i = size;
	while (i-- != 0 && *d != 0)
		d++;
	dst_len = d - dst;
	i = size - dst_len;
	if (i == 0)
		return (dst_len + ft_strlen(s));
	while (*s != 0)
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = 0;
	return (dst_len + (s - src));
}
