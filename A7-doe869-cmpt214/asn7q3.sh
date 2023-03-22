#Name: David Emmanuel
#NSID: DOE869
#SN: 11298443
#CMPT214 ASSIGNMENT 7

#! /bin/bash

NUM_COL=0
ar=()
for FILE in *
do
    if [ -d ${FILE} ]
    then
       NUM_COL=${FILE}
    fi
    #check for with spaces and without in filename
    if [ $FILE =*" "* ]
    then
       echo "'$FILE'" | tr -d '/'
    else [ ! "$FILE" = *" "* ]

        if [ ! $NUM_COL -gt 80 ]
        then
           ar+=( "$FILE" )
        else
           printf "rs: Display width 80 is less than column width $NUM_COL"
        fi
    fi
done
echo "${ar[*]}" | rs -w80 0 $NUM_COL
                                           
