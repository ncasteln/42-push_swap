# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nico <nico@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2024/03/15 13:05:43 by nico             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
FTPRINTF = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	./clst/basic_op.c \
	./clst/stack_op.c \
	./clst/stack_dop.c \
	./validation/validation.c \
	./validation/ft_atol.c \
	./validation/free_double_ptr.c \
	./sorting/sorting.c \
	./sorting/sorting_utils.c \
	./bit/bit_op.c \
	./mapping/mapping.c \
	./mapping/mapping_utils.c \
	./print/print_bits.c \
	./print/clst_print.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FTPRINTF) $(OBJS)
	@echo "Compile $(NAME)"
	@cc $(CFLAGS) $(OBJS) -o $(NAME) ./libs/libft/$(LIBFT) ./libs/ft_printf/$(FTPRINTF)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./libs/libft/

$(FTPRINTF):
	@$(MAKE) -C ./libs/ft_printf/

clean:
	@echo "$@ $(NAME)"
	@$(MAKE) clean -C ./libs/libft/
	@$(MAKE) clean -C ./libs/ft_printf/
	@rm -f $(OBJS)

fclean: clean
	@echo "$@ $(NAME)"
	@$(MAKE) fclean -C ./libs/libft/
	@$(MAKE) fclean -C ./libs/ft_printf/
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
