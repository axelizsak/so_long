# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aizsak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 08:31:08 by aizsak            #+#    #+#              #
#    Updated: 2023/01/28 18:55:21 by aizsak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src

BIN_DIR = bin

SRC = $(SRC_DIR)/clean.c \
      $(SRC_DIR)/parsing.c \
      $(SRC_DIR)/mlx_base.c \
      $(SRC_DIR)/pathfinding.c \
      $(SRC_DIR)/get.c \
      $(SRC_DIR)/pathfinding2.c \
      $(SRC_DIR)/event.c \
      $(SRC_DIR)/event2.c \
      $(SRC_DIR)/main.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

LIB_PATH = ./libft

MLX_PATH = ./mlx

LIB = -Llibft -lft

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes

CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH) -g3

all :  $(BIN_DIR) $(NAME)

$(BIN_DIR):
		@ mkdir -p $(BIN_DIR)

$(OBJ) :		$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(BIN_DIR) $(OBJ)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

clean :
		@ $(MAKE) -s clean -C $(LIB_PATH)
		@ rm -f $(OBJ)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all $(SRC_DIR) clean fclean re
