/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <udelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:50:39 by udelorme          #+#    #+#             */
/*   Updated: 2016/01/12 11:24:14 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define ERR_RET -1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_file
{
	int				fd;
	int				read;
	char			tmp[BUFF_SIZE + 1];
	char			*buf;
	struct s_file	*next;
}				t_file;

int				get_next_line(int const fd, char **line);

#endif
