# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 11:43:18 by udelorme          #+#    #+#              #
#    Updated: 2018/02/12 11:25:52 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = clang
FLAGS = -Wall -Werror -Wextra 
LIBFLAGS = -shared -fPIC
NAME = libft_malloc_$(HOSTTYPE).so
#NAME = libft_malloc_mdr.so
SRC = ft_malloc.c thread.c memory.c memory_2.c memory_3.c free_memory.c print.c

OBJ = $(SRC:.c=.o)

SRCDIR = src/
OBJDIR = obj/
INCDIR = includes/
LIBDIR = libft/

LIB = $(LIBDIR)libft.a

SRCS = $(addprefix $(SRCDIR),$(SRC))
OBJS = $(addprefix $(OBJDIR),$(OBJ))

$(NAME): $(LIB) $(OBJS)
	$(CC) $(LIBFLAGS) -o $(NAME) $^
	ln -s $(NAME) libft_malloc.so 2>/dev/null

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(FLAGS) -I $(INCDIR) -I $(LIBDIR)includes -o $@ -c $<

$(LIB):
	make re -C $(LIBDIR)

clean:
	rm -rf $(OBJS)
	@rmdir $(OBJDIR) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)
	rm -rf libft_malloc.so &2>/dev/null

re: fclean all

verbose: LIBFLAGS += -D VERBOSE 
verbose: FLAGS += -D VERBOSE 
verbose: re

lftclean:
	$(MAKE) -C $(LIBDIR) clean

lftfclean:
	$(MAKE) -C $(LIBDIR) fclean

.PHONY: all clean fclean re
