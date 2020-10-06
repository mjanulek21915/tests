./mk.sh

random=0
multiple_flags=1
precision=0
show_all=0


start=$(date +'%s')
null_char="r"
text_list=("|" )
flag_list=("r" " " "-" "+" "0")
width_list=("r" '*' "0" "1" "3" "4" "5" "42")
prec_list=("r" '.*' ".0" ".1" ".3" ".4" ".5" ".42")
conv_list=("d")
count_list=("0" "-5" "5")
whole_list=("r" " " "-" "+" "0" '*' "1" '.*' ".0" ".1")
path="logs/log_$start"

mkdir $path

if [ $random -eq 1 ]
then
	for conv in "${conv_list[@]}"
	do
		if [ $conv == "X" ]
		then
			log_diff="${path}/log_diff_precision_random_x_big_${start}"
			log_full="${path}/log_diff_precision_full_random_x_big_${start}"
			log_segfault="${path}/log_segfault_precision_random_x_big_${start}"
		else
			log_diff="${path}/log_diff_precision_random_${conv}_${start}"
			log_full="${path}/log_diff_precision_full_random_${conv}_${start}"
			log_segfault="${path}/log_segfault_precision_random_${conv}_${start}"
		fi
		echo "LOG_DIFF conv : ${conv}">$log_diff
		echo "LOG_SEGFAULT conv : ${conv}">$log_segfault
		echo "testing random flags $conv"
		for text in "${text_list[@]}"
		do
			for element_a in "${whole_list[@]}"
			do
				for element_b in "${whole_list[@]}"
				do
					for element_c in "${whole_list[@]}"
					do
						for element_d in "${whole_list[@]}"
						do
							old_ifs=$IFS
							IFS=""
							fmt="$text%$element_a$element_b$element_c$element_d$conv$text"
							temp_test=$(./a.out.rnd $fmt "0" "r")
							if [ $? != 0 ]
							then
								echo "    SEGFAULT TEST"
								echo "SEGFAULT TEST : ${fmt//"r"}" >> $log_segfault
							fi
							temp_ref=$(./a.out.rnd $fmt "1" "r")
							if [ $? != 0 ]
							then
								echo "    SEGFAULT REF"
								echo "SEGFAULT REF : ${fmt//"r"}" >> $log_segfault
							fi
							if [ -z $temp_test ] || [ -z $temp_ref ]
							then
								echo "    TEST VIDE : ${fmt//"r"}" 
								echo ""
								echo "TEST VIDE : ${fmt//"r"}" >> $log_diff
								echo "test : ${temp_test}" >> $log_diff
								echo "ref. : ${temp_ref}" >> $log_diff
								echo "" >> $log_diff
							elif [ $temp_test != $temp_ref ] || [ $show_all == 1 ]
							then
								echo "    DIFF : ${fmt//"r"}" 
								echo ""
								echo "DIFF : ${fmt//"r"}" >> $log_diff
								echo "test : ${temp_test}" >> $log_diff
								echo "ref. : ${temp_ref}" >> $log_diff
								echo "" >> $log_diff
							else
								echo "DIFF : ${fmt//"r"}" >> $log_diff
								echo "test : ${temp_test}" >> $log_diff
								echo "ref. : ${temp_ref}" >> $log_diff
								echo "" >> $log_diff
							fi
							IFS=$old_ifs
						done
					done
				done
			done
		done
	done
fi

if [ $precision -eq 1 ]
then
	old_ifs=$IFS
	IFS=""
	for conv in "${conv_list[@]}"
	do
		if [ $conv == "X" ]
		then
			log_diff="${path}/log_diff_precision_ref_x_big_${start}"
			log_segfault="${path}/log_segfault_precision_ref_x_big_${start}"
		else
			log_diff="${path}/log_diff_precision_ref_${conv}_${start}"
			log_segfault="${path}/log_segfault_precision_ref_${conv}_${start}"
		fi
		echo "LOG_DIFF conv : ${conv}">$log_diff
		echo "LOG_SEGFAULT conv : ${conv}">$log_segfault
		echo "testing precision $conv"
		for text in "${text_list[@]}"
		do
			for flag_a in "${flag_list[@]}"
			do
				for flag_b in "${flag_list[@]}"
				do
					for width in "${width_list[@]}"
					do
						for prec in "${prec_list[@]}"
						do
							fmt="${text}%$flag_a$flag_b$width$prec${conv}${text}"
							if [[ ( ( $width == '*' ) && ( $prec != '.*' ) ) || ( ( $width != '*' ) && ( $prec == '.*' ) ) ]]
							then
								for count in ${count_list[@]}
								do
									temp_test="$(./a.out.ref "$fmt" "$width" "$prec" "$conv" "0" "r" "$count")"
									if [ $? != 0 ]
									then
										echo "    SEGFAULT TEST"
										echo "SEGFAULT TEST : ${fmt//"r"} COUNT : $count" >> $log_segfault
									fi
									temp_ref="$(./a.out.ref "$fmt" "$width" "$prec" "$conv" "1" "r" "$count")"
									if [ $? != 0 ]
									then
										echo "    SEGFAULT REF"
										echo "SEGFAULT REF : ${fmt//"r"} COUNT : $count" >> $log_segfault
									fi
									if [ -z $temp_test ] || [ -z $temp_ref ]
									then
										echo "    TEST VIDE : ${fmt//"r"} COUNT : $count" 
										echo ""
										echo "TEST VIDE : ${fmt//"r"} COUNT : $count" >> $log_diff
										echo "test : ${temp_test}" >> $log_diff
										echo "ref. : ${temp_ref}" >> $log_diff
										echo "" >> $log_diff
									elif [ $temp_test != $temp_ref ] || [ $show_all == 1 ]
									then
										echo "    DIFF : ${fmt//"r"} COUNT : $count" 
										echo ""
										echo "DIFF : ${fmt//"r"} COUNT : $count" >> $log_diff
										echo "test : ${temp_test}" >> $log_diff
										echo "ref. : ${temp_ref}" >> $log_diff
										echo "" >> $log_diff
									fi
								done
							elif [[ ( $width == '*' ) && ( $prec == '.*' ) ]]
							then
								for count in ${count_list[@]}
								do
									for count_b in ${count_list[@]}
									do
										temp_test="$(./a.out.ref $fmt "$width" "$prec" "$conv" "0" "r" "$count" "$count_b")"
										if [ $? != 0 ]
										then
											echo "    SEGFAULT TEST"
											echo "SEGFAULT TEST : ${fmt//"r"} COUNTS : $count $count_b" >> $log_segfault
										fi
										temp_ref="$(./a.out.ref $fmt "$width" "$prec" "$conv" "1" "r" "$count" "$count_b")"
										if [ $? != 0 ]
										then
											echo "    SEGFAULT REF"
											echo "SEGFAULT REF : ${fmt//"r"} COUNTS : $count $count_b" >> $log_segfault
										fi
										if [ -z "$temp_test" ] || [ -z "$temp_ref" ]
										then
											echo "    TEST VIDE : ${fmt//"r"} COUNTS : $count $count_b" 
											echo ""
											echo "TEST VIDE : ${fmt//"r"} COUNTS : $count $count_b" >> $log_diff
											echo "test : ${temp_test}" >> $log_diff
											echo "ref. : ${temp_ref}" >> $log_diff
											echo "" >> $log_diff
										elif [ "$temp_test" != "$temp_ref" ] || [ $show_all == 1 ]
										then
											echo "    DIFF : ${fmt//"r"} COUNTS : $count $count_b" 
											echo ""
											echo "DIFF : ${fmt//"r"} COUNTS : $count $count_b" >> $log_diff
											echo "test : ${temp_test}" >> $log_diff
											echo "ref. : ${temp_ref}" >> $log_diff
											echo "" >> $log_diff
										fi
									done
								done
							else
								temp_test="$(./a.out.ref $fmt "$width" "$prec" "$conv" "0" "r")"
								if [ $? != 0 ]
								then
									echo "    SEGFAULT TEST"
									echo "SEGFAULT TEST : ${fmt//"r"}" >> $log_segfault
								fi
								temp_ref="$(./a.out.ref $fmt "$width" "$prec" "$conv" "1" "r")"
								if [ $? != 0 ]
								then
									echo "    SEGFAULT REF"
									echo "SEGFAULT REF : ${fmt//"r"}" >> $log_segfault
								fi
								if [ -z $temp_test ] || [ -z $temp_ref ]
								then
									echo "    TEST VIDE : ${fmt//"r"}" 
									echo ""
									echo "TEST VIDE : ${fmt//"r"}" >> $log_diff
									echo "test : ${temp_test}" >> $log_diff
									echo "ref. : ${temp_ref}" >> $log_diff
									echo "" >> $log_diff
								elif [ $temp_test != $temp_ref ] || [ $show_all == 1 ]
								then
									echo "    DIFF : ${fmt//"r"}" 
									echo ""
									echo "DIFF : ${fmt//"r"}" >> $log_diff
									echo "test : ${temp_test}" >> $log_diff
									echo "ref. : ${temp_ref}" >> $log_diff
									echo "" >> $log_diff
								fi
							fi
						done
					done
				done
			done
		done
	done
		IFS=$old_ifs
fi

if [ $multiple_flags -eq 1 ]
then
	width_list=("r" '*' "1" "12")
	prec_list=("r" '.*' ".1" ".12")
	count_list=("6" "-6" "4" "-4" "0")
	old_ifs=$IFS
	IFS=""
	for conv in "${conv_list[@]}"
	do
		if [ $conv == "X" ]
		then
			log_diff="${path}/log_diff_precision_multiple_flags_x_big_${start}"
			log_full="${path}/log_diff_precision_full_random_x_big_${start}"
			log_segfault="${path}/log_segfault_precision_multiple_flags_x_big_${start}"
		else
			log_diff="${path}/log_diff_precision_multiple_flags_${conv}_${start}"
			log_full="${path}/log_diff_precision_full_multiple_flags_${conv}_${start}"
			log_segfault="${path}/log_segfault_precision_multiple_flags_${conv}_${start}"
		fi
		echo "LOG_DIFF conv : ${conv}">$log_diff
		echo "LOG_FULL conv : ${conv}">$log_full
		echo "LOG_SEGFAULT conv : ${conv}">$log_segfault
		echo "testing multiple flags : $conv"
		for text in "${text_list[@]}"
		do
			for flag_a in "${flag_list[@]}"
			do
				for flag_b in "${flag_list[@]}"
				do
					for flag_c in "${flag_list[@]}"
					do
						for flag_d in "${flag_list[@]}"
						do
							for width in "${width_list[@]}"
							do
								for prec in "${prec_list[@]}"
								do
									fmt="${text}%$flag_a$flag_b$flag_c$flag_d$width$prec${conv}${text}"
									echo "$fmt"
									if [[ ( ( $width == '*' ) && ( $prec != '.*' ) ) || ( ( $width != '*' ) && ( $prec == '.*' ) ) ]]
									then
										for count in ${count_list[@]}
										do
											temp_test="$(./a.out.ref "$fmt" "$width" "$prec" "$conv" "0" "r" "$count")"
											if [ $? != 0 ]
											then
												echo "    SEGFAULT TEST"
												echo "SEGFAULT TEST : ${fmt//"r"} COUNT : $count" >> $log_segfault
											fi
											temp_ref="$(./a.out.ref "$fmt" "$width" "$prec" "$conv" "1" "r" "$count")"
											if [ $? != 0 ]
											then
												echo "    SEGFAULT REF"
												echo "SEGFAULT REF : ${fmt//"r"} COUNT : $count" >> $log_segfault
											fi
											echo "${fmt//"r"} COUNT : $count" >> $log_full
											echo "test : ${temp_test}" >> $log_full
											echo "ref. : ${temp_ref}" >> $log_full
											echo "" >> $log_full
											if [ -z $temp_test ] || [ -z $temp_ref ]
											then
												echo "    TEST VIDE : ${fmt//"r"}" 
												echo ""
												echo "TEST VIDE : ${fmt//"r"} COUNT : $count" >> $log_diff
												echo "test : ${temp_test}" >> $log_diff
												echo "ref. : ${temp_ref}" >> $log_diff
												echo "" >> $log_diff
											elif [ $temp_test != $temp_ref ] || [ $show_all == 1 ]
											then
												echo "    DIFF : ${fmt//"r"}" 
												echo ""
												echo "DIFF : ${fmt//"r"} COUNT : $count" >> $log_diff
												echo "test : ${temp_test}" >> $log_diff
												echo "ref. : ${temp_ref}" >> $log_diff
												echo "" >> $log_diff
											fi
										done
									elif [[ ( $width == '*' ) && ( $prec == '.*' ) ]]
									then
										for count in ${count_list[@]}
										do
											for count_b in ${count_list[@]}
											do
												temp_test="$(./a.out.ref $fmt "$width" "$prec" "$conv" "0" "r" "$count" "$count_b")"
												if [ $? != 0 ]
												then
													echo "    SEGFAULT TEST"
													echo "SEGFAULT TEST : ${fmt//"r"} COUNTS : $count $count_b" >> $log_segfault
												fi
												temp_ref="$(./a.out.ref $fmt "$width" "$prec" "$conv" "1" "r" "$count" "$count_b")"
												if [ $? != 0 ]
												then
													echo "    SEGFAULT REF"
													echo "SEGFAULT REF : ${fmt//"r"} COUNTS : $count $count_b" >> $log_segfault
												fi
												echo "${fmt//"r"} COUNTS : $count $count_b" >> $log_full
												echo "test : ${temp_test}" >> $log_full
												echo "ref. : ${temp_ref}" >> $log_full
												echo "" >> $log_full
												if [ -z "$temp_test" ] || [ -z "$temp_ref" ]
												then
													echo "    TEST VIDE : ${fmt//"r"}" 
													echo ""
													echo "TEST VIDE : ${fmt//"r"} COUNTS : $count $count_b" >> $log_diff
													echo "test : ${temp_test}" >> $log_diff
													echo "ref. : ${temp_ref}" >> $log_diff
													echo "" >> $log_diff
												elif [ "$temp_test" != "$temp_ref" ] || [ $show_all == 1 ]
												then
													echo "    DIFF : ${fmt//"r"}" 
													echo ""
													echo "DIFF : ${fmt//"r"} COUNTS : $count $count_b" >> $log_diff
													echo "test : ${temp_test}" >> $log_diff
													echo "ref. : ${temp_ref}" >> $log_diff
													echo "" >> $log_diff
												fi
												# IFS=$old_ifs
											done
										done
									else
										temp_test="$(./a.out.ref $fmt "$width" "$prec" "$conv" "0" "r")"
										if [ $? != 0 ]
										then
											echo "    SEGFAULT TEST"
											echo "SEGFAULT TEST : ${fmt//"r"}" >> $log_segfault
										fi
										temp_ref="$(./a.out.ref $fmt "$width" "$prec" "$conv" "1" "r")"
										if [ $? != 0 ]
										then
											echo "    SEGFAULT REF"
											echo "SEGFAULT REF : ${fmt//"r"}" >> $log_segfault
										fi
										echo "${fmt//"r"}" >> $log_full
										echo "test : ${temp_test}" >> $log_full
										echo "ref. : ${temp_ref}" >> $log_full
										echo "" >> $log_full
										if [ -z $temp_test ] || [ -z $temp_ref ]
										then
											echo "    TEST VIDE : ${fmt//"r"}" 
											echo ""
											echo "TEST VIDE : ${fmt//"r"}" >> $log_diff
											echo "test : ${temp_test}" >> $log_diff
											echo "ref. : ${temp_ref}" >> $log_diff
											echo "" >> $log_diff
										elif [ $temp_test != $temp_ref ] || [ $show_all == 1 ]
										then
											echo "    DIFF : ${fmt//"r"}" 
											echo ""
											echo "DIFF : ${fmt//"r"}" >> $log_diff
											echo "test : ${temp_test}" >> $log_diff
											echo "ref. : ${temp_ref}" >> $log_diff
											echo "" >> $log_diff
										fi
									fi
								done
							done
						done
					done
				done
			done
		done
	done
		IFS=$old_ifs
fi
echo "time : $SECONDS"
