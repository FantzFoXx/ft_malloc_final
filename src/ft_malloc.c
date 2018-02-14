/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:16:02 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/14 11:37:09 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	free(void *ptr)
{
	lock_mutex();
	free_chunk(ptr);
	unlock_mutex();
}

void	*malloc(size_t size)
{
	void	*ret;

	lock_mutex();
	ret = NULL;
	ret = allocate_block(size);
	unlock_mutex();
	return (ret);
}

/*
**void	*reallocf(void *ptr, size_t size)
**{
**#ifdef VERBOSE
**	ft_mtrace("reallocf", "PASS");
**#endif
**	return (realloc(ptr, size));
**}
*/

void	*realloc(void *ptr, size_t size)
{
	t_chunk *tmp;
	void	*ret;

	lock_mutex();
	ret = NULL;
	if (!ptr)
	{
		ret = allocate_block(size);
		unlock_mutex();
		return (ret);
	}
	tmp = NULL;
	tmp = browse_memory(ptr);
	if (!tmp)
		tmp = browse_memory(ptr);
	if (!tmp)
		tmp = browse_memory(ptr);
	if (!tmp)
	{
		unlock_mutex();
		return (NULL);
	}
	ret = reallocate_block(tmp, size);
	unlock_mutex();
	return (ret);
}
