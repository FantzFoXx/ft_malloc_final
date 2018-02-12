/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:10:03 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/19 15:18:54 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strdup_tab(char **data)
{
	char	**new;
	int		size_data;
	int		i;

	size_data = 0;
	if (data)
		while (data[size_data] != 0)
			size_data++;
	new = (char **)malloc(sizeof(char *) * (size_data + 1));
	new[size_data] = NULL;
	i = -1;
	if (data)
		while (++i < size_data)
			new[i] = ft_strdup(data[i]);
	return (new);
}
