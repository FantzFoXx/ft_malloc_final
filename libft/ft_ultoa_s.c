/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:42:59 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/20 14:45:19 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en string dans str
*/

t_ul	ft_ultoa_s(unsigned long n, char *str)
{
	unsigned long	len;
	unsigned long	i;
	unsigned long	ret;

	i = n;
	len = 1;
	while (i /= 10)
		++len;
	i = -1;
	str[len] = 0;
	ret = len;
	while (--len > i)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	return (ret);
}
