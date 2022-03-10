#!/bin/bash
letters="ABCDEFGHIJ"
echo What contest are you in?

read contest

echo "$contest"? That\'s awesome!

echo How many question are there?

read questions

mkdir ../"$contest"

for ((i=0; i< $questions; i++)) 
do
	letter="${letters:$i:1}"
	mkdir ../"$contest"/Problem\ "${letters:$i:1}"
	
	cp ./standard/main.cpp ../"$contest"/Problem\ "${letters:$i:1}"/main.cpp 

	cp ./standard/standard.cbp ../"$contest"/Problem\ "${letters:$i:1}"/Problem\ $letter.cbp

	cp ./standard/standard.layout ../"$contest"/Problem\ "${letters:$i:1}"/Problem\ $letter.layout
	string="Problem "$letter
	sed -i -e "s/standard/$string/g" ../"$contest"/Problem\ "${letters:$i:1}"/Problem\ $letter.cbp 
done

