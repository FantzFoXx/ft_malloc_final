/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:11:58 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:12:02 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en base
*/

char		*ft_imtoa_base(intmax_t n, char *base)
{
	intmax_t	i;
	intmax_t	nbase;
	intmax_t	len;
	char		*str;

	if ((nbase = (intmax_t)ft_strlen(base)) < 2 || ft_strocu(base))
		return (NULL);
	len = 1;
	i = n;
	while (i /= nbase)
		++len;
	if ((str = (char *)malloc(sizeof(char) * (len + 2))))
	{
		if ((i = (n < 0)))
		{
			str[0] = '-';
			str[len] = base[-1 * (n % nbase)];
			n = -1 * (n / nbase);
		}
		str[len + i] = 0;
		--i;
		while (--len > i && (str[len] = base[n % nbase]))
			n /= nbase;
	}
	return (str);
}
