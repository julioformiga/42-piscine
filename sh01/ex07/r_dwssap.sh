#!/bin/sh
FT_LINE1=7
FT_LINE2=15
cat /etc/passwd | sort -r | awk 'NR >= '$FT_LINE1' && NR <= '$FT_LINE2 | awk '{split($0, a, ":"); print a[1]}' | xargs -n20 | tr -t ' ' ', ' | tr '\n' '.\n'
