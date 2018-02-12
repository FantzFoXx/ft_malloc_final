/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:12:35 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/02 18:08:01 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_map			*get_map_struct(t_type type)
{
	t_map *map;

	map = g_env.map;
	while (map)
	{
		if (!map->full && map->type == type)
			break ;
		map = map->next;
	}
	return (map);
}

t_chunk			**get_chunk_struct(t_type type)
{
	t_map *map;

	map = g_env.map;
	while (map && map->full && map->type != type)
		map = map->next;
	if (map)
		return (&(map->chunks));
	return (NULL);
}

int				enough_space_left(t_chunk *chunk, size_t size)
{
	int calc;

	calc = chunk->size - sizeof(t_chunk);
	if (calc >= (int)size)
		return (1);
	else
		return (0);
}

void			init_new_page(t_chunk *chunk, t_type type, size_t size)
{
	unsigned char *addr;

	chunk->type = type;
	chunk->size = size - sizeof(t_chunk) - sizeof(t_map);
	chunk->free = 1;
	addr = (unsigned char *)chunk;
	addr += sizeof(t_chunk);
	chunk->addr = (void *)addr;
	chunk->next = NULL;
}

t_chunk			*init_chunk(t_chunk *chunk, t_type type, size_t size)
{
	unsigned char	*new_address;
	size_t			old_size;
	t_chunk			*old_next;

	old_size = chunk->size;
	old_next = chunk->next;
	chunk->type = type;
	chunk->size = size;
	chunk->free = 0;
	new_address = (unsigned char *)chunk->addr;
	new_address += size;
	chunk->next = (t_chunk *)new_address;
	chunk->next->type = type;
	chunk->next->free = 1;
	chunk->next->addr = new_address + sizeof(t_chunk);
	chunk->next->next = old_next;
	chunk->next->size = old_size - sizeof(t_chunk) - size;
	return (chunk);
}
