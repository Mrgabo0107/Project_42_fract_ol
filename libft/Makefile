# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:26:55 by gamoreno          #+#    #+#              #
#    Updated: 2022/08/15 16:56:38 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compilation ###

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I.

### Executable ###

NAME	=	libft.a

### Inculdes ###

OBJ_PATH = objs
HEADER = includes
SRC_PATH = sources

### Source Files ###

SOURCES	= 	ft_strcmp.c ft_atof.c ft_isdigit.c ft_substr.c ft_strchr.c\
		ft_strlen.c ft_strdup.c ft_itoa.c ft_strjoin.c ft_ftoa.c\
		ft_putstr_fd.c
			

### Objects ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all: tmp $(NAME)

tmp:
	@mkdir -p objs

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
		@echo "$(GREEN)libft made succesfully$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(CYAN)Creation of object file -> $(CYAN)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus
