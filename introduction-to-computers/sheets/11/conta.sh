#!/bin/bash

counter="0"

for c in "$@"
do
	if [[ -d "$c" ]]
	then
		counter="$(($counter+1))"
	fi
done

echo "$counter"
