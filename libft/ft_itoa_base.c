/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:11:29 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:11:30 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en base
*/

char		*ft_itoa_base(int n, char *base)
{
	int		i;
	int		nbase;
	int		len;
	char	*str;

	if ((nbase = (int)ft_strlen(base)) < 2 || ft_strocu(base))
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
			str[len] = base[-(n % nbase)];
			n = -(n / nbase);
		}
		str[len + i] = 0;
		--i;
		while (--len > i && (str[len] = base[n % nbase]))
			n /= nbase;
	}
	return (str);
}
