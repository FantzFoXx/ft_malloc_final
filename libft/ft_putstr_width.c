/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:10:25 by mmichel           #+#    #+#             */
/*   Updated: 2016/05/17 21:10:25 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche n carractere
** si str est plus petit que n: complete par des espaces
** si str est plus grand que n: tronque str
*/

void	ft_putstr_width(const char *str, int n)
{
	int		len;
	char	*buf;

	len = ft_strlen(str);
	buf = NULL;
	if (len < n)
	{
		if (!(buf = (char *)ft_memallocset(sizeof(char) * (n + 1), ' ')))
		{
			OUT_OF_MEMORY;
			return ;
		}
		ft_strncpy(buf, str, len);
	}
	else
	{
		if (!(buf = ft_strdup(str)))
		{
			OUT_OF_MEMORY;
			return ;
		}
		ft_strcpy(buf + n - 2, "..");
	}
	write(1, buf, n);
	free(buf);
}

void	ft_putnbr_width(int nb, int n)
{
	char	*str;

	if (!(str = ft_itoa(nb)))
	{
		OUT_OF_MEMORY;
		return ;
	}
	ft_putstr_width(str, n);
	free(str);
}
