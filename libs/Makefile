# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 15:12:01 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/24 17:10:49 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libs.a
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
LIBFTSRC = ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c \
	./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c \
	./libft/ft_strlcat.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c \
	./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_strdup.c \
	./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strmapi.c \
	./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putnbr_fd.c
LIBFT_OBJS = $(LIBFTSRC:.c=.o)

FTPRINTF = ./ft_printf/libftprintf.a
FTPRINTSRC = ./ft_printf/ft_printf.c \
	./ft_printf/print_char.c \
	./ft_printf/print_string.c \
	./ft_printf/print_signed.c \
	./ft_printf/print_unsigned.c \
	./ft_printf/print_hex.c \
	./ft_printf/get_digit_len.c
FTPRINTF_OBJS = $(FTPRINTSRC:.c=.o)

# VPATH = ./libft:./ft_printf

$(NAME): $(LIBFT) $(FTPRINTF)
	ar rcs $(NAME) $(LIBFT_OBJS) $(FTPRINTF_OBJS)

# %.o: %.c
# 	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(FTPRINTF):
	$(MAKE) -C ./ft_printf

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME)
