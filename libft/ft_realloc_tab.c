/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:01:39 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/19 15:18:37 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_realloc_tab(char ***data, size_t size)
{
	char	**new;
	int		size_data;
	int		i;

	size_data = 0;
	if (*data)
		while ((*data)[size_data] != 0)
			size_data++;
	new = (char **)malloc(sizeof(char *) * (size_data + size + 1));
	new[size_data + size] = NULL;
	i = -1;
	if (*data)
	{
		while (++i < size_data)
			new[i] = (*data)[i];
		free(*data);
	}
	*data = new;
}
