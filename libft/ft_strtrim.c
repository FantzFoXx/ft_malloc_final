/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:53:11 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/21 12:54:27 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int				i;
	size_t			len;
	unsigned int	st;
	char			*trimed;

	len = ft_strlen(s);
	i = 0;
	st = 0;
	while (s[st] != 0 && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
		st++;
	if (s[st] == 0)
		return ((char *)ft_strdup(&s[st]));
	while (len - 1 != 0 && (s[len - 1] == ' ' || s[len - 1] == '\n'
				|| s[len - 1] == '\t'))
		len--;
	len -= (size_t)st;
	trimed = ft_strsub(s, st, len);
	return (trimed);
}
