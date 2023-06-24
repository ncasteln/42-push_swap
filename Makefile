# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/24 17:43:24 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBS = ./libs/libs.a
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	./clst/basic_op.c \
	./clst/stack_op.c \
	./validation/validation.c \
	./validation/ft_atol.c \
	./validation/free_double.c \
	./sorting/sorting.c \
	./sorting/sorting_utils.c \
	./bit/bit_op.c \
	./indexing/indexing.c \
	./print/print_bits.c \
	./print/clst_print.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	cc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBS):
	$(MAKE) -C ./libs

clean:
	$(MAKE) clean -C ./libs
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libs
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
