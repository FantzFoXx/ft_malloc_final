/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:06:06 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:06:06 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en base
*/

char		*ft_ulltoa_base(t_ull n, char *base)
{
	t_ull	nbase;
	t_ull	len;
	t_ull	i;
	char	*str;

	str = NULL;
	if ((nbase = (t_ull)ft_strlen(base)) > 1 && !ft_strocu(base))
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
