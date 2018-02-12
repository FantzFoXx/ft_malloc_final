/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:51:10 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/24 10:11:21 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdio.h>

char	*ft_strtrim_w(const char *s)
{
	int		i;
	int		j;
	char	*tmp;
	char	*new;

	tmp = ft_strtrim(s);
	new = ft_strnew(ft_strlen(tmp));
	i = -1;
	j = 0;
	while (tmp[++i])
	{
		if (tmp[i] == ' ' || tmp[i] == '	')
		{
			new[j++] = ' ';
			while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '	'))
				i++;
		}
		if (tmp[i])
			new[j] = tmp[i];
		j++;
	}
	free(tmp);
	tmp = ft_strdup(new);
	free(new);
	return (tmp);
}
