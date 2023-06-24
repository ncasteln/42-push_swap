# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 15:12:01 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/24 15:26:12 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libs.a
LIBFT = ./libft/libft.a
FTPRINTF = ./ft_printf/libftprintf.a

$(NAME): $(LIBFT) $(FTPRINTF)
	ar rcs $(NAME) $(LIBFT) $(FTPRINTF)

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
