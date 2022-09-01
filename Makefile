# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:34:13 by gamoreno          #+#    #+#              #
#    Updated: 2022/08/15 16:22:50 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compilation ###

CC      = cc
FLAGS  = -Wall -Wextra -Werror -g

### Executable ###

NAME   = fractol

### Includes ###

OBJ_PATH  = objs
HEADER = includes
SRC_PATH  = sources
MLX = minilibx-linux
LIBFT = libft

### Source Files ###

SOURCES =	main.c\
		parsing_1.c\
		parsing_2.c\
		parsing_3.c\
		matrix.c\
		math_compl_1.c\
		math_compl_2.c\
		math_compl_3.c\
		draw.c\
		draw_util_1.c\
		draw_util_2.c\
		draw_util_3.c\
		frac_util.c\
		fractals.c\
		init.c\
		events_util_1.c\
		events_util_2.c\
		events.c\
		color_1.c\
		color_2.c\
		
### Objects ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(NOC)"
	@make -C $(MLX)
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ -l:libft.a -lmlx -lXext -lX11 -lm
	@echo "$(GREEN)Project compiled succesfully$(NOC)"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/*.h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(CYAN)Creation of object file -> $(CYAN)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Cleaning libraries$(NOC)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Cleaning libraries files$(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: temporary, re, fclean, clean
