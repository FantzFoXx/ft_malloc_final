/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:16:46 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/02 15:42:09 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	lock_mutex(void)
{
	if (ft_memcheck(&g_lock, 0, sizeof(pthread_mutex_t)))
		pthread_mutex_init(&g_lock, NULL);
	pthread_mutex_lock(&g_lock);
}

void	unlock_mutex(void)
{
	pthread_mutex_unlock(&g_lock);
}
