# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 20:18:18 by mjanulek          #+#    #+#              #
#    Updated: 2020/02/18 01:19:38 by mjanulek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_pf_putchar.c \
ft_pf_putstr.c \
ft_pf_strlen.c \
ft_pf_write_char.c \
ft_pf_write_get_sign.c \
ft_pf_write_hex_a.c \
ft_pf_write_hex.c \
ft_pf_write_int.c \
ft_pf_write_n.c \
ft_pf_write_nlen.c \
ft_pf_write_padding.c \
ft_pf_write_percent.c \
ft_pf_write_ptr.c \
ft_pf_write_put_base.c \
ft_pf_write_str.c \
ft_pf_write_uint.c \
ft_printf.c \
ft_read_atoi.c \
ft_read_get_flags.c \
ft_read_iz_in.c \
ft_read.c \
ft_write.c

OBJ = $(SRC:.c=.o)

all: ${NAME}

$(NAME): ${OBJ}
	@ar rc ${NAME} ${OBJ}

bonus: all

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

clean:
	@rm -f ${OBJ}

fclean:	clean
	@rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re