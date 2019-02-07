# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/13 11:01:43 by jcorwin           #+#    #+#              #
#    Updated: 2019/01/22 12:47:41 by jcorwin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCE_PATH = ./srcs
SOURCE = colors.c pars.c pr_isdigit.c pr_wstrlen.c print_num.c print_wchar.c \
		ft_fprintf.c pr_atoi.c pr_strchri.c print_bin.c print_str.c \
		ft_printf.c pr_bufaddstr.c pr_strlen.c print_float.c print_unum.c
SRC = $(addprefix $(SOURCE_PATH)/,$(SOURCE))
OBJ = $(SOURCE:.c=.o)
INC = ./includes/ft_printf.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)

$(OBJ):
	@gcc -c $(FLAGS) $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
