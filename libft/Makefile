# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 17:09:04 by udelorme          #+#    #+#              #
#    Updated: 2016/06/07 13:32:00 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
BIN = exec
INCREP = includes/
OBJDIR = obj/
FLAGS = -Wall -Werror -Wextra
SRCLIBC = $(shell find .  -maxdepth 1 -type f | grep ".c$$" \
	| grep -vE "(/\.|main\.c|/\#)" )
SRC = $(SRCLIBC)

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR),$(OBJ))

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJDIR)%.o: %.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(FLAGS) -I $(INCREP) -o $@ -c $<

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BIN)

re : fclean all

.PHONY: all clean fclean re
