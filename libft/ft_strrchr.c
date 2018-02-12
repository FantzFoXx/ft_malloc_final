/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:24:20 by udelorme          #+#    #+#             */
/*   Updated: 2015/11/27 14:43:52 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		ch;

	ch = c;
	i = ft_strlen(s) + 1;
	while (--i >= 0)
		if (s[i] == ch)
			return ((char *)&s[i]);
	return (NULL);
}
