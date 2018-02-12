/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:17:03 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/16 09:15:41 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strtrim_mod(const char *s)
{
	int				i;
	size_t			len;
	unsigned int	st;
	char			*trimed;

	len = ft_strlen(s);
	i = 0;
	st = 0;
	while (s[st] != 0 && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'
				|| s[st] == '\r' || s[st] == '\v' || s[st] == '\f'))
		st++;
	while (len - 1 != 0 && (s[len - 1] == ' ' || s[len - 1] == '\n'
				|| s[len - 1] == '\t' || s[len - 1] == '\r'
				|| s[len - 1] == '\v' || s[len - 1] == '\f'))
		len--;
	len -= (size_t)st;
	trimed = ft_strsub(s, st, len);
	return (trimed);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		mult;
	char	*s;

	i = 0;
	mult = 1;
	result = 0;
	s = ft_strtrim_mod(str);
	if (s[0] == '-')
		mult = -1;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i] != 0 && ft_isdigit(s[i]))
	{
		result += (s[i] - 48);
		if (s[i + 1] != 0 && ft_isdigit(s[i + 1]))
			result *= 10;
		i++;
	}
	if (i >= 20)
		return (0);
	result *= mult;
	free(s);
	return (result);
}
