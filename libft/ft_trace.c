/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:43:59 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/22 18:44:49 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"

void	ft_trace(const char *mess, const char *s)
{
	ft_putstr(RED);
	if (mess)
	{
		ft_putstr(mess);
		ft_putstr(" : ");
	}
	else
		ft_putstr("trace : ");
	ft_putendl(s);
	ft_putstr(DEFAULT_COLOR);
}
