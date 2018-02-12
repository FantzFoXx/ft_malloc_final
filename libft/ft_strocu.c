/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strocu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:09:41 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:09:42 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Recherche de carractere comporatant des ocurances multiple
** 0 = non
*/

int	ft_strocu(const char *str)
{
	int		i;
	int		n;
	char	*stro;
	char	*strc;

	if (str && *str)
	{
		stro = (char *)str;
		strc = stro;
		while (*stro)
		{
			i = -1;
			n = 0;
			while (strc[++i])
				if (strc[i] == *stro)
					++n;
			if (n > 1)
				return (1);
			++stro;
		}
	}
	return (0);
}
