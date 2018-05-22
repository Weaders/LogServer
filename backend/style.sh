#!/bin/bash

# Use clang for all files

files=()
folders=()
folders[0]="Controllers/"
folders[1]="Server/"
folders[2]="Services/"

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

function getFilesFromFolder {

    folderPath="$SCRIPTPATH/$1"
    cd $folderPath

    filesNames="$(ls -a | grep -E '\.cpp$|\.h$')"

    for file in $filesNames; do 
        files+=("$folderPath$file")
    done

    for d in */; do
    if [[ $d != "*/" ]]; then
        getFilesFromFolder "$1$d"
    fi
    done
}

for var in "${folders[@]}"
do
    getFilesFromFolder $var
done

log="$(clang-format -style=file -i ${files[@]})"