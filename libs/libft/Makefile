# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:52:36 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/26 11:07:22 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) bonus

$(NAME): $(OBJS)
	@echo "Compile $(NAME)"
	@ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	@echo "Compile $@ $(NAME)"
	@ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c
	@cc -c $(CFLAGS) $< -o $@

clean:
	@echo "$@ $(NAME)"
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$@ $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
