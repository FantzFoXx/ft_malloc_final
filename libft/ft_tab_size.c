/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:06:12 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/19 15:19:04 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_tab_size(char **data)
{
	size_t size_data;

	size_data = 0;
	if (data)
		while (data[size_data] != 0)
			size_data++;
	return (size_data);
}
