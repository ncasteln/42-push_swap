# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/24 13:21:08 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FTPRINTF = ./ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	./clst/basic_op.c \
	./clst/stack_op.c \
	./validation/validation.c \
	./validation/ft_strchr.c \
	./validation/ft_atol.c \
	./validation/ft_split.c \
	./sorting/sorting.c \
	./sorting/sorting_utils.c \
	./bit/bit_op.c \
	./indexing/indexing.c \
	./print/ft_put.c \
	./print/print_bits.c \
	./print/clst_print.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc -g $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	cc -c $(CFLAGS) -o $@ $^ -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
