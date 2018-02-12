/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:40:34 by udelorme          #+#    #+#             */
/*   Updated: 2016/02/26 16:52:57 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_strnew(len);
	if (!new_str)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		new_str[i] = s1[i];
	ft_strcat(new_str, s2);
	return (new_str);
}
