/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:16:37 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/05 16:09:56 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_chunk		*try_place_chunk(t_chunk *chunk, t_map *map,
						size_t size)
{
	t_chunk		*new;

	if (chunk->free && size == chunk->size)
	{
		new = chunk;
		new->free = 0;
		map->free = 0;
		map->allocs++;
		return (new);
	}
	else if (chunk->free && chunk->size > (size + sizeof(t_chunk) + 1))
	{
		map->free = 0;
		map->allocs++;
		new = init_chunk(chunk, chunk->type, size);
		return (new);
	}
	return (NULL);
}

t_chunk				*create_free_chunk(t_map *map, size_t size, t_type type)
{
	t_chunk		*new;
	int			page_size;
	int			count;
	t_map		*page;
	t_chunk		*chunk;

	count = 0;
	chunk = map->chunks;
	while (chunk)
	{
		new = try_place_chunk(chunk, map, size);
		if (new)
			return (new);
		count++;
		chunk = chunk->next;
	}
	map->full = 1;
	page_size = calc_page_size(size);
	page = new_page(size);
	if (!page)
		return (NULL);
	init_new_page(page->chunks, type, page_size);
	return (create_free_chunk(page, size, type));
}

void				*create_chunk(t_type type, size_t size)
{
	t_chunk **chunks;
	t_chunk	*new;
	t_map	*map;
	int		page_size;

	chunks = get_chunk_struct(type);
	map = get_map_struct(type);
	if (!map)
	{
		page_size = calc_page_size(size);
		map = new_page(size);
		if (!map)
			return (NULL);
		init_new_page(map->chunks, type, page_size);
	}
	if (map)
		new = create_free_chunk(map, size, type);
	else
		return (NULL);
	return (new);
}

void				*reallocate_block(t_chunk *chunk, size_t size)
{
	void			*ret;
	unsigned char	*addr;
	size_t			new_size;
	t_chunk			cpy;

	addr = (unsigned char *)chunk;
	if (chunk->next && chunk->next->free &&
		size <= (chunk->size + chunk->next->size) && size > 0)
	{
		cpy = *chunk->next;
		new_size = size - chunk->size;
		chunk->size = size;
		addr += (size + sizeof(t_chunk));
		ft_memcpy((void *)addr, (const void *)&cpy, sizeof(t_chunk));
		chunk->next = (t_chunk *)addr;
		chunk->next->size -= new_size;
		ret = chunk->addr;
		return (ret);
	}
	if ((ret = allocate_block(size)) && ret)
	{
		ft_memcpy(ret, chunk->addr, chunk->size);
		free_chunk(chunk->addr);
	}
	return (ret);
}

void				*allocate_block(size_t size)
{
	t_chunk	*free_chunk;
	t_type	type;
	char	*mdr;

	free_chunk = NULL;
	if ((int)size < 0)
		return (NULL);
	if (size == 0)
		size = 1;
	type = get_page_type_from_size(size);
	free_chunk = create_chunk(type, size);
	if (!free_chunk)
		return (NULL);
	mdr = free_chunk->addr;
	return (free_chunk->addr);
}
