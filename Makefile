# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/15 09:23:08 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	ft_atoi.c \
	ft_split.c \
	clst.c
OBJS = $(SRC:.c=.o)

CLST = clst.c \
	clst_test.c \
	ft_atoi.c \
	ft_split.c
CLSTOBJS = $(CLST:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# CLISTS TESTING
clst: $(CLSTOBJS)
	cc $(CFLAGS) $(CLSTOBJS) -o $@

clst_clean:
	rm -f $(CLSTOBJS) clst

.PHONY: all clean fclean re
