# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 18:29:26 by kmykhail          #+#    #+#              #
#    Updated: 2018/04/10 11:27:37 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
LIBFT	=	./libft/libft.a
LIB		=	libftfdf.a
SRC_DIR	=	./src/
OBJ_DIR	=	./obj/
SRC		=	main.c button_mouse.c calcul_pixel.c helper_main.c print_and_helper.c
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(LIB)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(LIBFT) $(LIB) -lmlx -framework OpenGl -framework AppKit
	@rm libftfdf.a

$(LIB): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[3;36mfdf has been made\033[0m"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c src/fdf.h
	@mkdir -p $(OBJ_DIR)
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(LIBFT):
	@make -C ./libft

clean:
	@rm -rf $(LIBFT) $(LIB) $(OBJ_DIR) ./libft/obj
	@echo "\033[3;33mlibft.a have been deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[3;31fdf has been deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
