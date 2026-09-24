#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <caminho_do_ficheiro>"
    exit 1
fi

file_path="$1"

if [ ! -f "$file_path" ]; then
    echo "Error: file '$file_path' not found."
    exit 1
fi

filename_raw=$(basename "$file_path")
filename="${filename_raw%.*}"
dir_path=$(dirname "$file_path")

mkdir -p "$dir_path"/out/

./dbdia/bin/dbdia er "$file_path" "$dir_path"/out/"$filename".png

echo "Done!"
