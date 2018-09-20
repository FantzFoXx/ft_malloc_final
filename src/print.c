/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:58:56 by udelorme          #+#    #+#             */
/*   Updated: 2018/09/20 16:03:02 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	malloc_itoa_base(int n, char *base)
{
	int		i;
	int		nbase;
	int		len;
	char	str[100];

	if ((nbase = (int)ft_strlen(base)) < 2 || ft_strocu(base))
		return ;
	len = 1;
	i = n;
	while (i /= nbase)
		++len;
	if ((i = (n < 0)))
	{
		str[0] = '-';
		str[len] = base[-(n % nbase)];
		n = -(n / nbase);
	}
	str[len + i] = 0;
	--i;
	while (--len > i && (str[len] = base[n % nbase]))
		n /= nbase;
	ft_putstr(str);
	return ;
}

void	print_page_infos(t_type type)
{
	t_map	*map;

	map = g_env.map;
	while (map)
	{
		if (map->type == type)
		{
			if (type == TINY)
				ft_putstr("TINY : ");
			if (type == SMALL)
				ft_putstr("SMALL : ");
			if (type == LARGE)
				ft_putstr("LARGE : ");
			ft_putstr("0x");
			malloc_itoa_base((int)map, "0123456789ABCDEF");
			ft_putendl("");
			return ;
		}
		map = map->next;
	}
}

int		print_alloc_informations(t_chunk *chunk)
{
	ft_putstr("0x");
	malloc_itoa_base((size_t)chunk->addr, "0123456789ABCDEF");
	ft_putstr(" - ");
	ft_putstr("0x");
	malloc_itoa_base((size_t)chunk->addr + chunk->size, "0123456789ABCDEF");
	ft_putstr(" : ");
	malloc_itoa_base(chunk->size, "0123456789");
	ft_putendl("");
	return (chunk->size);
}

int		cross_chunks(t_chunk *tmp, t_type type)
{
	int total;

	total = 0;
	while (tmp)
	{
		if (!tmp->free && tmp->type == type)
			total += print_alloc_informations(tmp);
		tmp = tmp->next;
	}
	return (total);
}

void	show_alloc_mem(void)
{
	t_map	*map;
	t_type	type;
	int		total;

	lock_mutex();
	map = g_env.map;
	type = TINY;
	total = 0;
	while (type < 3)
	{
		print_page_infos(type);
		while (map)
		{
			total += cross_chunks(map->chunks, type);
			map = map->next;
		}
		map = g_env.map;
		type++;
	}
	ft_putstr("Total : ");
	malloc_itoa_base(total, "0123456789");
	ft_putendl(" octets");
	unlock_mutex();
}
