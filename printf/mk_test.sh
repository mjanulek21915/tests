cd ft_printf
make fclean re
make clean
cd .. 
gcc main_test.c ft_printf/libftprintf.a -fsanitize=address -Wall -Wextra -Werror

# gcc main_test.c -Wall -Wextra -Werror