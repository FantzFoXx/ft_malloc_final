/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 11:00:14 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/29 11:16:32 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_index(char *str, int index)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 3);
	ret[0] = ft_strsub(str, 0, index);
	ret[1] = ft_strsub(str, index + 1, ft_strlen(str) - index);
	ret[2] = NULL;
	return (ret);
}
