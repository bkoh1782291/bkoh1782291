##!/bin/bash
#gen() {
#	echo "depth is $2"
#
#	for i in {1..5}
#	do
#		# create random file
#		f=$(printf "$1/file%d" $i)
#		len=$(( ($RANDOM % 500) + 1 ))
#		s=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $len | head -n 1)
#		echo $s >> $f
#	done
#
#	if [ $2 -eq 4 ]; then
#		return 0
#	fi
#
#	for i in {1..5}
#	do
#		# create subfolders and recurse
#		f=$(printf "$1/folder%d" $i)
#		mkdir $f
#		depth=$(( $2 + 1 ))
#		gen $f $depth
#	done
#}
#dir=$( pwd )
#depth=1
#gen $dir $depth
#
