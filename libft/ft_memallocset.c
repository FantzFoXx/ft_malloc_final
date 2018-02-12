/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichel <mmichel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:32:26 by mmichel           #+#    #+#             */
/*   Updated: 2016/01/05 05:34:10 by mmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue de la memoire, initialise a 'c' et fini par 0
** Retourne la zone memoire fraichement alloue
*/

#include "libft.h"

void	*ft_memallocset(size_t size, int c)
{
	char *s;

	if (!(s = (char *)malloc(size + sizeof(char))))
		return (NULL);
	s[size] = 0;
	while (size--)
		((unsigned char*)s)[size] = (unsigned char)c;
	return (s);
}
