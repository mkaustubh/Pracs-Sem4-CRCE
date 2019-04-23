#!/bin/bash

# adduser adds a User
# deluser deletes a User
# ls displays file info
# mkdir -p creates directory
# touch creates file
# chmod modifies File/Directory permits -R Applies it recursively
# chown changes Owner
# chgroup changes Group


echo "$#"

if(("$#"==2)) && [ "$1" == 'a' ]
then
	adduser $2
elif [ "$#" -eq 2 ] && [ "$1" == 'b' ]
then
	deluser $2
	echo "Result $?"
elif [ "$#" -eq 3 ] && [ "$1" == 'c' ]
then
	if [ "$2" == 'f' ]
	then
		touch $3
	elif [ "$2" == 'd' ]
	then
		mkdir -p $3
	fi
elif [ "$#" -eq 2 ] && [ "$1" == 'd' ]
then
	rm -rf $2
elif   [ "$#" -eq 2 ] && [ "$1" == 'e' ]
then
	# ls displays File And Directory information
	ls -Aal $2
elif [ "$#" -eq 3 ] && [ "$1" == 'f' ]
then
	chmod -R $2 $3
elif [ "$#" -eq 4 ] && [ "$1" == 'g' ]
then
	if [ "$2" == "o" ]
	then
		# chown changes ownership
		chown -R $3 $4
	elif [ "$2" == "g" ]
	then
		# chgrp changes Group
		chgrp -R $3 $4
	fi
else
	echo "Error Faced. Exiting"
	exit 1
fi