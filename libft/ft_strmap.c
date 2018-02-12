/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:09:52 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/04 18:07:14 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*new_str;

	len = ft_strlen(s);
	new_str = NULL;
	new_str = ft_strnew(len);
	i = -1;
	if (new_str)
		while (s[++i] != 0)
			new_str[i] = f(s[i]);
	return (new_str);
}
