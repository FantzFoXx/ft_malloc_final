/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:13:31 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/20 14:45:10 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en string dans str
*/

t_ui	ft_uitoa_s(unsigned int n, char *str)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	ret;

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
