base=$PWD
echo "base = $PWD"
# if [ $# -gt 0 ]
# then
# 	cd $1
# fi

user_name="mjanulek"
date="$(date +"%Y/%m/%d %H:%M:%S") by $user_name"
user="$user_name <$user_name@student.42.fr>"

for elem in *.c
do
	if [ -e "$elem.temp" ]
	then
		echo "removing $elem.temp"
		rm "$elem.temp"
	fi
	if [ -e "$elem" ]
	then
		echo "adding header to $elem"
		mv "$elem" "$elem.temp"
		/home/aaa/S19/tests/printf/headers/a.out "$elem.temp" "/home/aaa/S19/tests/printf/headers/c_source" "$elem" "$user" "$date" > $elem
	else
		echo "no such thing as $elem"
	fi

done

cd $base