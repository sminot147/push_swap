# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 11:39:48 by sminot            #+#    #+#              #
#    Updated: 2024/12/21 18:14:54 by sminot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILE = main.c\
	utils.c\
	swap.c\
	rotate.c\
	reverse_rotate.c\
	bubblesort.c\

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
	rm -f $(OBJ)
	rm -f $(DEPS)

fclean : clean 
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

force :

re : fclean, all

-include $(DEPS)

.PHONY : all, clean, fclean, re, force