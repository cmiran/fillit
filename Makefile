# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 12:12:50 by cmiran            #+#    #+#              #
#    Updated: 2018/01/17 17:42:47 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=		gcc
CFLAGS=		-Wall -Werror -Wextra
NAME=		fillit

INC_DIR=	./include
INCS=		$(addprefix -I, $(INC_DIR))

LIB=		./libft.a

SRC_DIR=	./src
SRC=		main.c\
		parse.c\
		write.c\
		solve.c

OBJ_DIR=	./obj
OBJS=		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) 

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
