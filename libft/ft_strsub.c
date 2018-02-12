/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:05:31 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/16 09:15:42 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*trc;
	size_t	i;

	trc = ft_strnew(len);
	i = -1;
	if (trc)
	{
		while (++i < len)
			trc[i] = s[i + (size_t)start];
		trc[i] = 0;
	}
	return (trc);
}
