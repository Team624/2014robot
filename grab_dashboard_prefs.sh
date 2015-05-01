#!/bin/bash
cp "/c/Users/Public/624_dashboard_prefs.txt" "624_dashboard_prefs.txt"
#filter whitespace at the end of each line
sed -i 's/[ \t]*$//' "624_dashboard_prefs.txt"
git diff "624_dashboard_prefs.txt"