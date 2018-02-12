/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <udelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:32:02 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/21 10:53:05 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		lst_pushfile(t_file **file, int fd)
{
	t_file *new;
	t_file *index;

	index = *file;
	new = (t_file *)malloc(sizeof(t_file));
	if (new)
	{
		new->fd = fd;
		new->read = 0;
		new->buf = ft_strnew(0);
		ft_memset(new->tmp, 0, BUFF_SIZE);
		new->next = NULL;
		if (!*file)
			*file = new;
		else
		{
			while (index->next)
				index = index->next;
			index->next = new;
		}
	}
}

static t_file	*find_file(t_file **file, int fd)
{
	t_file *index;

	index = *file;
	if (index)
		while (index->next && fd != index->fd)
			index = index->next;
	if (!index || index->fd != fd)
	{
		lst_pushfile(file, fd);
		return (find_file(file, fd));
	}
	return (index);
}

static int		extract_line(char **buffer, int read, char **line)
{
	size_t		size_line;
	char		*new_buf;
	int			ret;

	size_line = -1;
	ret = 0;
	while (buffer[0][++size_line] != 0)
	{
		if (buffer[0][size_line] == '\n')
			break ;
	}
	*line = ft_strnew(size_line);
	ft_strncpy(*line, *buffer, size_line);
	if ((ft_strlen(*buffer) != 0 || read != 0))
		ret = 1;
	new_buf = ft_strsub(*buffer, size_line + 1,
			(ft_strlen(*buffer) - size_line));
	free(*buffer);
	*buffer = new_buf;
	return (ret);
}

static int		realloc_buffer(char **s1, char *s2)
{
	char *new;

	new = ft_strjoin(*s1, s2);
	if (!new)
		return (0);
	free(*s1);
	*s1 = new;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*cur;

	if (BUFF_SIZE < 0)
		return (ERR_RET);
	cur = find_file(&file, fd);
	if (!ft_strchr(cur->buf, '\n'))
		while ((cur->read = read(cur->fd, cur->tmp, BUFF_SIZE))
				&& cur->read != (0 ^ -1))
		{
			cur->tmp[cur->read] = 0;
			if (!(realloc_buffer(&cur->buf, cur->tmp)))
				return (ERR_RET);
			if (ft_strchr(cur->tmp, '\n'))
				break ;
		}
	if (cur->read == -1 || !line)
		return (ERR_RET);
	if (ft_strlen(cur->buf) != 0)
		return (extract_line(&cur->buf, cur->read, line));
	return (0);
}
