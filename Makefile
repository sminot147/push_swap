# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 11:39:48 by sminot            #+#    #+#              #
#    Updated: 2025/01/11 08:28:14 by sminot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src/

SRC_FILE = main.c\
	parsing.c\
	utils.c\

ACTION_DIR = src/action/

ACTION = swap.c\
	rotate.c\
	reverse_rotate.c\
	push.c\

SORT_DIR = src/sort/

SORT = sort_stack.c\
	sort_utils.c\
	sort_with.c\

FILE = $(addprefix $(SRC_DIR), $(SRC_FILE))\
	$(addprefix $(ACTION_DIR), $(ACTION))\
	$(addprefix $(SORT_DIR), $(SORT))\

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -MMD -g3
INCLUDE = include

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(FILE:.c=.o))

DEPS =  $(addprefix $(OBJ_DIR)/, $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) force

$(LIBFT) : force
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean 
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

force :

re : fclean all

-include $(DEPS)

.PHONY : all, clean, fclean, re, force