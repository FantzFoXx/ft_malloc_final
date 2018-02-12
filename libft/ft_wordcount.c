/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:54:24 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/03 16:40:08 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *s, char c)
{
	int i;
	int cpt_w;

	i = -1;
	cpt_w = 0;
	while (s[++i] != 0)
		if (s[i] != c)
		{
			cpt_w++;
			while (s[i] != c && s[i] != 0)
				i++;
			i--;
		}
	return (cpt_w);
}
