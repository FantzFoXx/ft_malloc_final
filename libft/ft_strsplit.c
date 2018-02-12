/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:19:22 by udelorme          #+#    #+#             */
/*   Updated: 2016/01/07 15:17:26 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_splitword(const char *s, char c)
{
	size_t	i;
	char	*split;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i = i + 1;
	split = ft_strnew(i);
	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		split[i] = s[i];
		i = i + 1;
	}
	return (split);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		cpt_w;
	char	**split_tab;
	int		w_count;

	cpt_w = ft_wordcount(s, c);
	split_tab = (char **)malloc(sizeof(char *) * (cpt_w + 1));
	if (!split_tab)
		return (NULL);
	split_tab[cpt_w] = NULL;
	i = 0;
	w_count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			split_tab[w_count] = ft_splitword(&s[i], c);
			i += ft_strlen(split_tab[w_count]);
			w_count++;
		}
	}
	return (split_tab);
}
