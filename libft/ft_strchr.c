/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:51:51 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/04 14:28:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*occur_ptr;

	occur_ptr = NULL;
	i = -1;
	while (s[++i] != 0)
	{
		if (s[i] == c)
		{
			occur_ptr = &s[i];
			return ((char *)&s[i]);
		}
	}
	if (s[i] == 0 && c == 0)
	{
		occur_ptr = &s[i];
		return ((char *)&s[i]);
	}
	return (NULL);
}
