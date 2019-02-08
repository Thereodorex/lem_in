# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 11:57:34 by jcorwin           #+#    #+#              #
#    Updated: 2019/02/08 23:56:17 by rrhaenys         ###   ########.fr        #
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
MLX = -framework OpenCL -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
F=

all: libs $(NAME)

$(NAME): $(SRC) $(INC)
	gcc -g -o $(NAME) -I $(INCLUDE_PATH) -Iminilibx_macos $(SRC) -L ./llibft/ -lft -L ./lprintf/ -lftprintf $(MLX)

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
	make -C generator
	./generator/lem-in_gen $(ANT) $(NODE) > test.txt; cat test.txt | ./$(NAME)

re: fclean all
