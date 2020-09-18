# mets la valeur de la variable bonus a 1 si tu veux tester tes fichiers _bonus, 0 pour les fichiers normaux.
# attention a ne pas laisser d espace entre le signe "egal" et la valeur (ou le nom de la variable pour autant).

is_bonus=0

# ci-dessous est specifie le nom de dossier dans lequel se trouveront les fichiers de get_next_line. a mettre entre "".
gnl="get_next_line"





is_linux=0
if [ $(uname -s) == Linux ]
then
	echo LINUX
	open_max='-D OPEN_MAX=1024'
	echo $open_max
	is_linux=1
fi

if [ -f "a.out" ]
then
	rm a.out
fi

if [ ! -z $1 ]
then
	buffer_size=$1
else
	buffer_size=1
fi

if [ ! -z $2 ]
then
	iterations_count=$2
else
	iterations_count=1
fi

if [ $is_bonus == 1 ]
then
	bonus="_bonus"
	sed -i -e 's/get_next_line.h/get_next_line_bonus.h/g' main_bench.c
	sed -i -e 's/get_next_line.h/get_next_line_bonus.h/g' main_fd_error.c
else
	sed -i -e 's/get_next_line_bonus.h/get_next_line.h/g' main_bench.c
	sed -i -e 's/get_next_line_bonus.h/get_next_line.h/g' main_fd_error.c
fi

filename_list=$(cat liste_fichiers)

for filename in $filename_list
do
	echo $filename
	gcc \
	-Wall -Wextra -Werror \
	-I $gnl \
	-fsanitize=address -g \
	main_bench.c \
	$gnl/get_next_line$bonus.c $gnl/get_next_line_utils$bonus.c $gnl/get_next_line$bonus.h \
	-D BUFFER_SIZE=$buffer_size $open_max
	./a.out $filename $iterations_count
done

if [ $is_linux == 1 ]
then
	echo "compile sur linux, OPEN_MAX defini a 1024"
fi