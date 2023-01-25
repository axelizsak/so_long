# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aizsak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 08:31:08 by aizsak            #+#    #+#              #
#    Updated: 2023/01/25 08:57:35 by aizsak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/

CC = gcc

OBJ = $(SRC:.c=.o)

LIB_PATH = libft/

LIB = -Llibft -lft

INCLUDES = ./includes

CFLAGS =	-Werror -Wextra -Wall -lmlx -lXext -lX11 -I$(INCLUDES)

all :	$(SRC)

$(SRC) :     $(OBJ)
			$(MAKE) -C $(LIB_PATH)
			$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(SRC)
clean :
	$(MAKE) clean -C $(LIB_PATH)
	rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C $(LIB_PATH)
	rm -f $(SRC)

re : fclean $(SRC)

PHONY: all clean fclean re
