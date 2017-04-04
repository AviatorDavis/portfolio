#!/bin/bash
#project3.sh
#Donald Davis
#12/1/16


#declare vairables
vaild="checking"
calc="unknown"
selection="waitomg"

#check for passed ARGUMENTS
if [ $# -ne 0 ]
then
	#they passed more than 0 arguments
	#make the first arguemnt the SELECTION to be tested.
	selection=$1
	echo "Accepting Agrument"
else
	#they passed NO arguments
	echo "No Arguments passed"
	#move along
fi
	

#check selection
while [ $vaild != "T" ]
do
#IF statement to take path of SELECTION
	if [ $selection = "K" ] || [ $selection = "k" ]
	then
		#change calculations and sentinal
		calc=K
		vaild=T
		echo "SELETED: Fahrenheit -> Kelvin"
	elif [ $selection = "F" ] || [ $selection = "f" ]
	then	
		#change calculations and sentinal
		calc=F
		vaild=T
		echo "SELECTED: Kelvin -> Fahrenheit"
#not f or k
	else
		#prompt for selection of conversion
		echo "'K': for converting Fahrenheit to Kelvin"
		#echo "OR"
		echo "'F': for converting Kelvin to Fahrenheit"
		read selection garbage
	fi	
#done when seleciton is vaild.
done

#got selecion from the user
#WHILE loop to read line by line into the varriable data
while read data
do
	
	#IF $selection decieds which function to run. 
	if [ $calc = "F" ]
	#PASS Kelvin to CALC Farh
	then
		calculation=`project3/fahr_kel 1 $data`
		kelvin=`echo $calculation | cut -d " " -f 1`
		fahrenheit=`echo $calculation | cut -d " " -f 2`
	fi
	
	if [ $calc = "K" ]
	#PASS Farh to CALC Kelvin
	then 	
		calculation=`project3/fahr_kel 2 $data`
		fahrenheit=`echo $calculation | cut -d " " -f 1`
		kelvin=`echo $calculation | cut -d " " -f 2`
	fi

	#echo caluculations into OUTPUT for later pasting
	echo -e "\t$fahrenheit\t\t\t$kelvin" >> project3/project3.output
	echo -e "---------------\t\t\t\b\b\b---------------" >> project3/project3.output
done < project3/project3.input



#clear screen
tput clear

#display header with date and name
echo "--------------- ---------------"
echo "CIS129 project 3  solution Donald Davis"
echo "Today is  `date +"%m-%d-%Y/%T"`"
echo "--------------- ---------------"
#now display the labels
tput cup 4 0;echo "Fahrenheit Temperature"
tput cup 4 29;echo "Kelvin Temperature"
tput cup 5 0;echo "---------------"
tput cup 5 29;echo "---------------"

#paste old and new data
cat project3/project3.output
#delete the temp output file
rm project3/project3.output

