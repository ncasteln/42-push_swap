# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/24 15:27:21 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBS = ./libs/libs.a
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

$(NAME): $(OBJS) $(LIBS)
	cc -g $(CFLAGS) $(OBJS) -o $@

$(LIBS):
	$(MAKE) -C ./libs

%.o: %.c
	cc -c $(CFLAGS) -o $@ $^ -g

clean:
	$(MAKE) clean -C ./libs
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libs
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
