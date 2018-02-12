/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:27:19 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/04 14:16:54 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t c;

	i = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i] != 0 && i < n)
	{
		c = 0;
		while (s1[i + c] == s2[c] && s2[c] != 0 && (i + c) < n)
			c++;
		if (s2[c] == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
