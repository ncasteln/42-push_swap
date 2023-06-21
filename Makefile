# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/21 10:26:40 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	clst.c \
	clst_moves.c \
	validation.c \
	./utils/ft_strchr.c \
	./utils/ft_atol.c \
	./utils/ft_split.c \
	./utils/ft_put.c \
	sorting.c \
	sorting_utils.c
OBJS = $(SRC:.c=.o)

CLST = clst.c \
	clst_test.c \
	clst_moves.c \
	sorting.c \
	./utils/ft_atol.c \
	./utils/ft_split.c
CLSTOBJS = $(CLST:.c=.o)

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

# CLISTS TESTING
clst: $(CLSTOBJS)
	cc $(CLSTOBJS) $(CFLAGS) -o $@

clst_clean:
	rm -f $(CLSTOBJS) clst

.PHONY: all clean fclean re
