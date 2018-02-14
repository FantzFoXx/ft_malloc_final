/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:17:18 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/14 11:20:38 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <pthread.h>
# include <sys/mman.h>
# include <errno.h>

# include "libft.h"

# include <stdio.h>
# include <errno.h>

/*
** defines
*/

# define TINY_ALLOC		64
# define SMALL_ALLOC	2048
# define LARGE_ALLOC

# define META_PAGE		4096

# define TRUE			1
# define FALSE			0

# define RED      			"\033[91m"
# define DEFAULT_COLOR "\033[0;m"

/*
** enums
*/

typedef enum		e_type
{
	TINY, SMALL, LARGE
}					t_type;

/*
** structs
*/

typedef struct		s_chunk
{
	void			*addr;
	size_t			size;
	t_type			type;
	struct s_chunk	*next;
	uint8_t			free;
}					t_chunk;

typedef struct		s_map
{
	size_t			size;
	t_chunk			*chunks;
	struct s_map	*next;
	struct s_map	*prev;
	unsigned char	full;
	unsigned char	free;
	short			allocs;
	t_type			type;
}					t_map;

typedef struct		s_meta
{
	t_chunk			*tchunk;
	t_chunk			*schunk;
	t_chunk			*lchunk;
	t_map			*map;
}					t_meta;

/*
** globals
*/

pthread_mutex_t		g_lock;
t_meta				g_env;

/*
** main functions
*/

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem(void);

/*
** void	*reallocf(void *ptr, size_t size);
*/

/*
** thread safe functions
*/

void				lock_mutex(void);
void				unlock_mutex(void);

/*
** other
*/

void				*allocate_block(size_t size);
void				*reallocate_block(t_chunk *chunk, size_t size);
void				free_chunk(void *addr);
void				malloc_itoa_base(int n, char *base);
t_chunk				*browse_memory(void *addr);
size_t				calc_page_size_from_type(t_type type);
size_t				calc_page_size(size_t size_alloc);
int					unmap_zone(t_map **map);
int					print_int(int a);
void				ft_mtrace(const char *mess, const char *s);
t_map				*get_map_struct(t_type type);
t_chunk				**get_chunk_struct(t_type type);
int					enough_space_left(t_chunk *chunk, size_t size);
t_chunk				*init_chunk(t_chunk *chunk, t_type type, size_t size);
size_t				calc_page_size_from_type(t_type type);
size_t				calc_page_size(size_t size_alloc);
void				*init_map(void *map, t_type type, size_t size);
t_type				get_page_type_from_size(size_t size);
void				*new_page(size_t size);
void				init_new_page(t_chunk *chunk, t_type type, size_t size);
#endif
