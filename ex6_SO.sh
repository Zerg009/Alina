#!/bin/sh
recur()
{
	# move to new directory
	cd $1

	filescount=$(find -maxdepth 1 -type f | wc -l)
	#echo $1 contains $filescount lines
	# check if is empty
	if ! [ "$(ls -A)" ]; then
		
		
		return	
	fi
	
	# check if has no files 
	if [ $filescount -eq 0 ];
	then
		echo '-----'
		pwd 
		echo '-----'
		echo
	fi 

	
	# loop through every filex
	for i in $(ls)
	do
		#echo $1: $i

		#check if it's a directory
		if [ -d $i ];
		then
			# if it is, then move recursively
			recur $i

			# go back 
			cd ..
		fi

	done
}

if [ -d $1 ].
then
	recur $1
fi
