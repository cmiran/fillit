# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 12:12:50 by cmiran            #+#    #+#              #
#    Updated: 2018/01/22 18:29:03 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=		gcc
CFLAGS=		-Wall -Werror -Wextra
NAME=		fillit

INC_DIR=	./include
INCS=		$(addprefix -I, $(INC_DIR))

LIB_DIR=	./libft
LIB=		./libft/libft.a
LIB_LINK=	 -L $(LIB_DIR) -lft

SRC_DIR=	./src
SRC=		main.c\
		parse.c\
		write.c\
		solve.c

OBJ_DIR=	./obj
OBJS=		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_LINK) -o $@

obj:
	@mkdir -p obj

$(LIB):
	@make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) 

clean:
	@make clean -C ./libft
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
