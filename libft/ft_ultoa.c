/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:12:23 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:12:27 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(t_ul n)
{
	t_ul	i;
	t_ul	len;
	char	*str;

	i = n;
	len = 1;
	while (i /= 10)
		++len;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		str[len] = 0;
		while (--len)
		{
			str[len] = n % 10 + 48;
			n /= 10;
		}
		str[len] = n % 10 + 48;
	}
	return (str);
}
