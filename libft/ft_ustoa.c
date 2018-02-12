/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:14:58 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:15:03 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ustoa(t_us n)
{
	t_us	i;
	t_us	len;
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
