/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:35:21 by udelorme          #+#    #+#             */
/*   Updated: 2016/02/15 12:00:56 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_create_square(int length)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * length + 1);
	if (!tab)
		return (NULL);
	tab[length] = 0;
	i = 0;
	while (i < length)
	{
		tab[i] = (char *)malloc(sizeof(char) * length + 1);
		if (!tab[i])
			return (NULL);
		j = 0;
		tab[i][length] = 0;
		while (j < length)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}
