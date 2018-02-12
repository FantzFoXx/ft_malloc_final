/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:24:49 by udelorme          #+#    #+#             */
/*   Updated: 2015/11/26 20:34:24 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int c;

	i = 0;
	if (s2[0] == 0)
		return ((char *)&s1[0]);
	while (s1[i] != 0)
	{
		c = 0;
		while (s1[i + c] == s2[c] && s2[c] != 0)
			c++;
		if (s2[c] == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
