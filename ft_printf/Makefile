# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahrach <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 18:34:11 by aahrach           #+#    #+#              #
#    Updated: 2022/11/12 18:34:30 by aahrach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_lhex.c ft_uhex.c ft_address.c ft_unsigned.c\

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $?

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
