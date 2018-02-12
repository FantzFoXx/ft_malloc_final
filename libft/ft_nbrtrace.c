/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:55:46 by udelorme          #+#    #+#             */
/*   Updated: 2016/04/22 18:44:47 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"

void	ft_nbrtrace(const char *mess, int i)
{
	ft_putstr(RED);
	if (mess)
	{
		ft_putstr(mess);
		ft_putstr(" : ");
	}
	else
		ft_putstr("trace : ");
	ft_putendl(ft_itoa(i));
	ft_putstr(DEFAULT_COLOR);
}
