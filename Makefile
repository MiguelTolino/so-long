# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2024/12/20 15:59:03 by migueltolin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable 

SRCS_DIR:= src/

SRCS := $(wildcard $(SRCS_DIR)*.c)
#SRCS_BONUS :=	$(wildcard $(SRCS_DIR_BONUS)*.c) \
#				$(wildcard $(GNL)*.c) \
#				$(wildcard $(SRCS_DIR_BONUS)config/*.c) \
#				$(wildcard $(SRCS_DIR_BONUS)engine/*.c)

OBJS := $(SRCS:%.c=%.o)
#OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME:= so_long
CC:= gcc
MLXFLAG =   -Llib/minilibx-linux files/lib/minilibx-linux/libmlx.a -lXext -lX11 -lmlx -lm
CFLAGS:= -Wall -Werror -Wextra -I.
MLX_DIR:= lib/minilibx
RM :=	rm -rvf
DEBUG_FLAG:= -g
GNL:= files/lib/get_next_line/


all:	libft minilibx $(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(GNL)*.c -o $(NAME) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a 

bonus: libft minilibx $(OBJS_BONUS) 
	$(CC) $(OBJS_BONUS) $(GNL)*.c -o $(NAME) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a 

$(%.o): $(%.c)
		$(CC) -c $^ -o $@ 
		@echo "Creating objects"

libft:
		make -C $(LIBFT_DIR)
		
minilibx:
		make -C $(MLX_DIR)

clean:
		@echo "Removing objects"
		make -C $(LIBFT_DIR) clean
		$(RM) $(OBJS) $(OBJS_BONUS)
fclean:
		make clean
		$(RM) $(NAME) $(IMG)
		make -C $(LIBFT_DIR) fclean
		@echo "Removed executable"
msg:
		@echo  "\e[42m                   \e[0m"
		@echo  "\e[92mAll files compiled"
		@echo  "cub3D built"
		@echo  "Execute--> ./cub3D 'name'.cub"
		@echo  "\e[93mENJOY IT!!"
		@echo  "\e[42m                   \e[0m"

re:
	make fclean all
	@echo "All files has been deleted and recompiled"


.PHONY: clean fclean all re objects debug minilibx libft objects bonus
