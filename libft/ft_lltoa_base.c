/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:10:12 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:10:14 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convertie n en base
*/

char		*ft_lltoa_base(t_ll n, char *base)
{
	t_ll	i;
	t_ll	nbase;
	t_ll	len;
	char	*str;

	if ((nbase = (t_ll)ft_strlen(base)) < 2 || ft_strocu(base))
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
