/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uctoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:06:26 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:06:27 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en base
*/

char		*ft_uctoa_base(t_uc n, char *base)
{
	int		nbase;
	int		len;
	int		i;
	char	*str;

	str = NULL;
	if ((nbase = (int)ft_strlen(base)) > 1 && !ft_strocu(base))
	{
		len = 1;
		i = n;
		while (i /= nbase)
			++len;
		if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		{
			str[len] = 0;
			while (len)
			{
				str[--len] = base[n % nbase];
				n /= nbase;
			}
		}
	}
	return (str);
}
