/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:57:41 by udelorme          #+#    #+#             */
/*   Updated: 2015/11/27 21:37:04 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] != 0 && i < (n - 1))
	{
		if (s1[i] != s2[i] || s2[i] == 0)
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
