/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:14:52 by udelorme          #+#    #+#             */
/*   Updated: 2015/11/27 14:14:43 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		occuring;

	str = (const unsigned char *)s;
	occuring = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (str[i] == occuring)
			return ((void *)&str[i]);
	return (NULL);
}
