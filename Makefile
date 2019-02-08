# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 11:57:34 by jcorwin           #+#    #+#              #
#    Updated: 2019/02/07 11:19:41 by jcorwin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCE_PATH = ./srcs/
SOURCE = *.c
SRC = $(addprefix $(SOURCE_PATH), $(SOURCE))
OBJ = $(SOURCE:.c=.o)
INCLUDE_PATH = ./includes/
INCLUDE = ft_printf.h get_next_line.h libft.h lem_in.h
INC = $(addprefix $(INCLUDE_PATH), $(INCLUDE))
FLAGS = -Wall -Werror -Wextra

all: libs $(NAME)

$(NAME): $(SRC) $(INC)
	gcc -o $(NAME) -I $(INCLUDE_PATH)  $(SRC) -L ./llibft/ -lft -L ./lprintf/ -lftprintf

libs:
	cd llibft/ && make
	cd lprintf/ && make

clean:
	cd llibft/ && make clean
	cd lprintf/ && make clean

fclean:
	cd llibft/ && make fclean
	cd lprintf/ && make fclean
	rm -f $(NAME)

re: fclean all
