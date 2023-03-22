#Name: David Emmanuel
#NSID: DOE869
#SN: 11298443
#CMPT214 ASSIGNMENT 7


#! /bin/bash

NUM_COL=0
max=
ar=()

#checking to get not more than one argument on the command line
if [ $# -gt 1 ]
then
   echo "Usage Message: lsdir.sh $0"S
   exit 1
fi
if [ ! -e "$1" ]
then
   printf "could not change current working directory to '$1'.\n"
   exit 2
else
   cd $1
fi
for FILE in *
do
    if [ -d ${FILE} ]
    then
        max=${FILE}
        NUM_COL=$(( 80/(max+1)))
    fi
    #check for spaces with and without in filename
    if [ "$FILE" =*" "* ]
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
                                                                       
