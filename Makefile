# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 11:57:34 by jcorwin           #+#    #+#              #
#    Updated: 2019/02/07 17:19:42 by rrhaenys         ###   ########.fr        #
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
	gcc -g -o $(NAME) -I $(INCLUDE_PATH)  $(SRC) -L ./llibft/ -lft -L ./lprintf/ -lftprintf

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

test: all
	./$(NAME) maps/1.map

re: fclean all
