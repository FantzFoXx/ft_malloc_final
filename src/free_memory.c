/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:03:28 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/02 15:39:39 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_chunk		*browse_memory(void *addr)
{
	t_map			*map;
	void			*end_addr;
	unsigned char	*calc;
	t_chunk			*chunk;

	map = g_env.map;
	while (map)
	{
		calc = (unsigned char *)map;
		end_addr = (void *)(calc + map->size);
		if (addr > (void *)map && addr < end_addr)
		{
			chunk = map->chunks;
			while (chunk)
			{
				if (addr == chunk->addr)
					return (chunk);
				chunk = chunk->next;
			}
		}
		map = map->next;
	}
	return (NULL);
}

int			unmap_zone(t_map **map)
{
	t_map	*update_map;
	t_map	*test;

	test = g_env.map;
	if (*map)
	{
		update_map = (*map)->prev;
		if ((*map)->prev)
			(*map)->prev->next = (*map)->next;
		else
			g_env.map = (*map)->next;
		if ((*map)->next)
			(*map)->next->prev = update_map;
		munmap(*map, (*map)->size);
		*map = update_map;
	}
	return (0);
}

void		free_allocation(t_map *map, t_chunk *chunk)
{
	t_chunk	*old_next;

	if (chunk->free == 0)
	{
		chunk->free = 1;
		map->allocs--;
	}
	if (chunk->next && chunk->next->free)
	{
		old_next = chunk->next;
		chunk->size += chunk->next->size + sizeof(t_chunk);
		chunk->next = chunk->next->next;
		ft_bzero(old_next, sizeof(t_chunk));
		free_allocation(map, chunk);
	}
	if (map && map->allocs == 0)
		map->free = 1;
}

void		free_chunk(void *addr)
{
	t_map			*map;
	void			*end_addr;
	unsigned char	*calc;
	t_chunk			*chunk;

	map = g_env.map;
	while (map)
	{
		calc = (unsigned char *)map;
		end_addr = (void *)(calc + map->size);
		if (addr > (void *)map && addr < end_addr)
		{
			chunk = map->chunks;
			while (chunk)
			{
				if (addr == chunk->addr)
					free_allocation(map, chunk);
				chunk = chunk->next;
			}
		}
		if (map->free)
			unmap_zone(&map);
		if (map)
			map = map->next;
	}
}
