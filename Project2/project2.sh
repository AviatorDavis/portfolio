#!/bin/bash
#project2.sh
#Donald Davis
#11/11/2016
# script that will take information from a file, and print (users choice of printer) identical form letters to each recipent. Either E-197, E-199, E-194 printers or to project2.output. Prompt the user for thier choice.
#check to see if parameters were entered
#intilaze variables
e197=t197laser1
e199=t199laser1
e194=t194laser1
output=project2.output
vaild=N
#place holder for input
selection=garbage
#toggle sentinal for printing or output
printing=Y

#clear output
echo > /home/ddavis68/project2.output
if [ $# -ne 0 ]
then
	#if first paramtere is string	
	if test -n $1;then
		#at least 1 argument
		echo "Passed a agrument string"
		#place argument into the input check
		input=$1
	fi
else
	#they didnt have at least one argument
	echo "No arguments were passed"
	#prompt read for the input of printers
	echo "Enter the correct destination for the selected printer 'E-194' 'E-197' 'E-199' 'output'"
	read input
fi


#checked input, start while loop for vaild selection
while [ $vaild = N ]
do
	#run case to vaildate input
	case $input in
		[E,e]-197)
			selection=$e197
			vaild=Y	
			;;
		[E,e]-199)
			selection=$e199
			vaild=Y
			;;
		[E,e]-194)
			selection=$e194
			vaild=Y
			;;
		[O,o]utput)
			selection=$output
			vaild=Y
			printing="N"
			;;
		*)
			echo -e "Invalid input. enter only: 'E-194' 'E-197' 'E-199' 'output' "
			read input
			;;
 	esac
done
#finshed selection location

#read input file
while read line
do

#save variables into indivudal parts
#name
	last=`echo $line | cut -f1 -d ","`
	first=`echo $line | cut -f2 -d ","`
	gender=`echo $line | cut -f3 -d ","`
	
#address
	office=`echo $line | cut -f4 -d ","`
	address=`echo $line | cut -f5 -d ","`
	city=`echo $line | cut -f6 -d ","`
	state=`echo $line | cut -f7 -d ","`
	zip=`echo $line | cut -f8 -d ","`
	depart=`echo $office | cut -c1-1`
#enter dashes in office
#first charcter letter. add "-" next 3 numbers at location 1. add "-" last letter starting a 4
office=`echo ${office:0:1}-${office:1:3}-${office:4:1}`

#print gender as Mr. Mrs.
if [ $gender = M ]
then 
	gender=Mr.
else
#not man, must be woman
	gender=Mrs.
fi


#display proper building
if [ $depart = E ]
then
#enginerring
	depart=Engineering
else
	depart=Production
fi

#create temp to store message
tempMsg=/home/ddavis68/project2.message
#chmod 666 $tempMsg
echo "Dear $gender$last" > $tempMsg
echo >> $tempMsg
echo "Welcome to Widgets, Inc. $first. This letter is to inform you of your assigned office space at Widgets, Inc. is in the main $depart building. Your office is $office located at $address, $city $state. $zip" >> $tempMsg
echo >> $tempMsg
echo "Sincerely," >> $tempMsg
echo >> $tempMsg
echo "The Boss" >> $tempMsg
#create spacing between messges
echo >> $tempMsg
echo >> $tempMsg

#put tempMessage into the selected

#print to selected
if [ $printing = "N" ]
then
	cat $tempMsg >> $output
	#spacing for output
	echo >> $output
	echo "..Finished uploading message for $last in output"
else
	lpr $tempMsg -P $selection
	echo "..Finished printing message for $last"
fi
#finish line reading
done < project2.input
#delete temp message
rm $tempMsg
