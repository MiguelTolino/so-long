# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2024/12/20 16:35:24 by migueltolin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# AUTHOR: mmateo-t
# USAGE:
# make          # compile all binaries
# make clean    # remove all object files
# make fclean   # remove all object files and the executable
# make re       # recompile everything from scratch

# Colors
GREEN := \033[0;32m
YELLOW := \033[0;33m
RED := \033[0;31m
RESET := \033[0m

# Directories
SRCS_DIR := src/
LIBFT_DIR := lib/libft
MLX_DIR := lib/minilibx_opengl

# Source and Object files
SRCS := $(wildcard $(SRCS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)

# Executable name
NAME := so_long

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
LIBS := -lm
RM := rm -rf

# Library flags
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_FLAGS := -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft
MLX := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Default target
all: $(NAME)
	@echo "$(GREEN)All files have been compiled$(RESET)"

# Link the final executable
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS) $(LIBS)
	@echo "$(GREEN)Executable $(NAME) created$(RESET)"

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile minilibx
$(MLX):
	make -C $(MLX_DIR)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Creating object file: $@$(RESET)"

# Clean object files
clean:
	$(RM) $(OBJS)
	@echo "$(RED)All object files have been removed$(RESET)"
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Clean object files and executable
fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)All object files and the executable have been removed$(RESET)"
	make -C $(LIBFT_DIR) fclean

# Recompile everything from scratch
re: fclean all
	@echo "$(GREEN)All files have been deleted and recompiled$(RESET)"

# Phony targets
.PHONY: clean fclean all re
