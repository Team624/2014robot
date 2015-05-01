#!/bin/bash

scan_git() {
	files1=`git status --porcelain | grep " M \".*\"" | perl -nle 'm/ M ([\"].*)/; print $1'`
	files2=`git status --porcelain | grep " M [^\"].*" | perl -nle 'm/ M (.*)/; print $1'`
	files="$files1 $files2"
	if [ "$files" = " " ]; then
		git status
		echo
		echo "Nothing left to diff. Everything's already checked into the index."
		echo "  (use \"git reset HEAD <file>...\" to unstage files)"
		files=""
	else
		echo "Listing changes not added to index:"
		files="\"***Quit***\" \"***Git Status***\" $files"
	fi
}

scan_git

while [ "$files" != "" ]; do

#echo files $files

eval set $files
select opt in "$@"
do
	#echo "File=\"$opt\""
	if [ "$opt" = "***Quit***" ]; then
		git status
		exit
	fi
	if [ "$opt" = "***Git Status***" ]; then
		git status
		echo -n "Press enter to continue... "
		read response
	else
		
		### DIFF? ###
		echo -n "  Diff file \"$opt\" [Y/n]? "
		read response
		if [ "$response" != "n" ]; then
			echo "   ~ git diff \"$opt\" ..."
			git diff "$opt"
			
			
			### ADD? ###
			echo -n "  Add file \"$opt\" [Y/n]? "
			read response
			if [ "$response" != "n" ]; then
				echo "   ~ git add \"$opt\""
				git add "$opt"
			else
				
				### REVERT? ###
				echo -n "  Revert file \"$opt\" [y/N]? "
				read response
				if [ "$response" = "y" ]; then
#					### VERIFY 1 ###
#					echo -n "    REVERT: Are you sure [y/N]? "
# 				read response
#					if [ "$response" = "y" ]; then
#						### VERIFY 2 ###
#						echo "  ****This cannot be undone****"
#						echo -n "    REVERT: Are you really sure [y/N]?"
#						read response
#						
#						if [ "$response" = "y" ]; then
							echo "   ~ git checkout -- \"$opt\""
							echo -n "   [press enter to execute]"
							read response
							git checkout -- "$opt"
#						fi
#					fi
        fi
				
			fi
		fi
		
	fi
	
	break
done

scan_git

done