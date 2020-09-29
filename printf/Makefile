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






libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
libft/ft_memmove.c libft/ft_memset.c libft/ft_strchr.c libft/ft_strdup.c \
libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c \
libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c libft/ft_toupper.c \
libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c \
libft/ft_itoa.c libft/ft_strmapi.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
arg_treat.c arg_typer.c flag_number.c flags_treat.c ft_printf.c \
arg_process.c ft_dectohex.c ft_flag_center.c ft_pourcent_treat.c \
ft_char_treat.c ft_pointer_treat.c ft_string_treat.c ft_number_treat.c \

SRC_BONUS = libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c \
libft/ft_lstsize_bonus.c libft/ft_lstadd_back_bonus.c \
libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c \
libft/ft_lstmap_bonus.c libft/ft_laststr_indexof_bonus.c \
libft/ft_firststr_indexof_bonus.c libft/ft_lstlast_bonus.c \
libft/ft_charstock_bonus.c libft/ft_strstock_bonus.c \
libft/ft_strnstock_bonus.c libft/ft_itoa_base.c libft/ft_uitoa.c \
libft/ft_memstock.c \

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