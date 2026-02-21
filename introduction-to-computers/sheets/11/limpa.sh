#!/bin/bash

base="/home/miguel/Desktop/university/introduction-to-computers/sheets/10"
trash="/home/miguel/Desktop/university/introduction-to-computers/sheets/10/LIXO"
delete="0"

exists=`ls -la $base | grep LIXO | wc -l`

if [[ "$exists" == "0" ]]
then
	mkdir -p "$trash"
fi

for f in "$@"
do
	if [[ "$f" == "-f" ]]
	then
		delete="1"
	else
		mv "$f" "$trash"
	fi
done

if [[ "$delete" == "1" ]]
then
	rm -rf "$trash"
	mkdir -p "$trash"
fi
