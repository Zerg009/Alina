#!/bin/sh

recur()
{
	# store working directory for find 
	curr=$(pwd)

	# move to new directory
	cd $1

	# list in directory
	for i in $(ls)
	do
		# check if it's a file
		if [ -f $i ]
		then
			# check if file contains the word $2
			if [ "$(egrep -w "$2" $i)" ]
			then 
				# check if file is also in DIR2
				
				# get all occurences of files from DIR2
 				file_path=$(find "${curr}/$3" -name $i) 
				
				if ! [ "$file_path" = "" ]
				then

					# check if found file has the word
					if [ "$(egrep -w "$2" $file_path)" ]
					then
						echo "\t!Found in $file_path"
					fi
				fi
			fi
		fi
		# check if it's directory
		if [ -d $i ]
		then
			# recursive
			recur $i $2 $3
		fi
	done
	# move back
	cd ..
}

recur $1 $3 $2
