RED='\033[0;32m'
PRINTFA='../ft_printf/libftprintf.a'
NC='\033[0m' # No Color
echo 'Please enter a path for libftprintf.a'
	rm -f test.c
	cp newmain.c ft.c
	sed 's/printf/ft_printf/g' ft.c > ft_printf.c
	rm ft.c
	printf "$sCompiling printf main...${NC}\n"
	gcc ${PRINTFA} newmain.c 2> /dev/null
	./a.out > printf.txt
	echo "$sCompiling ft_printf main...${NC}\n"
	gcc -I ../ft_printf ../ft_printf/*.c main_ft.c
	./a.out > ft_printf.txt
	rm a.out
	diff printf.txt ft_printf.txt > printf.diff
	cat -e printf.diff
	printf "$sYou have "
	cat -e printf.diff | grep "<" | wc -l | tr -d " " | tr -d "\n"
	printf " errors \n"
