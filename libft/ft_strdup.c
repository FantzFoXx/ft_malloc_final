/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:26:53 by udelorme          #+#    #+#             */
/*   Updated: 2016/02/26 16:51:38 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = ft_strnew(ft_strlen(s1));
	if (!dup)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		dup[i] = s1[i];
	return (dup);
}
