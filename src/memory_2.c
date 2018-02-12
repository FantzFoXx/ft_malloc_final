/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:09:42 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/02 17:20:33 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t			calc_page_size_from_type(t_type type)
{
	size_t	alloc_size_max;
	size_t	ret;
	size_t	pagesize;

	if (type == TINY)
		alloc_size_max = TINY_ALLOC;
	else if (type == SMALL)
		alloc_size_max = SMALL_ALLOC;
	pagesize = getpagesize();
	if (type == LARGE)
		return (0);
	else
		ret = ((alloc_size_max + sizeof(t_chunk)) * 100) / pagesize;
	ret += 1;
	return (ret * pagesize);
}

size_t			calc_page_size(size_t size_alloc)
{
	size_t	alloc_size_max;
	size_t	ret;
	size_t	pagesize;

	if (size_alloc <= TINY_ALLOC)
		alloc_size_max = TINY_ALLOC;
	else if (size_alloc <= SMALL_ALLOC)
		alloc_size_max = SMALL_ALLOC;
	else
		alloc_size_max = size_alloc;
	pagesize = getpagesize();
	if (size_alloc > SMALL_ALLOC)
		ret = (alloc_size_max + (sizeof(t_chunk) * 2) + sizeof(t_map))
			/ pagesize;
	else
		ret = ((alloc_size_max + sizeof(t_chunk)) * 100 + sizeof(t_map) +
			sizeof(t_chunk)) / pagesize;
	ret += 1;
	return (ret * pagesize);
}

void			*init_map(void *map, t_type type, size_t size)
{
	t_map	*tmap;
	t_map	*env_map;

	if (map == MAP_FAILED)
		return (NULL);
	env_map = g_env.map;
	tmap = map;
	tmap->size = size;
	tmap->full = 0;
	tmap->free = 1;
	tmap->allocs = 0;
	tmap->type = type;
	tmap->chunks = (t_chunk *)tmap + 1;
	tmap->next = NULL;
	tmap->prev = NULL;
	if (!g_env.map)
		g_env.map = tmap;
	else
	{
		while (env_map->next)
			env_map = env_map->next;
		env_map->next = tmap;
		tmap->prev = env_map;
	}
	return (map);
}

t_type			get_page_type_from_size(size_t size)
{
	t_type type;

	if (size <= TINY_ALLOC)
		type = TINY;
	else if (size <= SMALL_ALLOC)
		type = SMALL;
	else
		type = LARGE;
	return (type);
}

void			*new_page(size_t size)
{
	size_t	alloc_size;
	t_type	type;
	void	*map;

	type = get_page_type_from_size(size);
	alloc_size = calc_page_size(size);
	map = mmap(0, alloc_size, PROT_READ | PROT_WRITE, MAP_ANON |
		MAP_PRIVATE, -1, 0);
	return (init_map(map, type, alloc_size));
}
