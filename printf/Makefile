# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 20:18:18 by mjanulek          #+#    #+#              #
#    Updated: 2020/02/18 01:19:38 by pjanulek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 


SRC_BONUS = 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: ${NAME}

$(NAME): ${OBJ} ${OBJ_BONUS}
	@ar rc ${NAME} ${OBJ} ${OBJ_BONUS}

%.o: %.c
	@${CC} ${CFLAGS} -c -o $@ $?
clean:
	@rm -f ${OBJ} ${OBJ_BONUS}

fclean:	clean
	@rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re