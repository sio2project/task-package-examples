#!/bin/bash

set -e

# If you want to add whole directory you need to put * after dir name.
# Example: in/* .
_files=( doc/trezad.pdf prog/*.cpp prog/*.py in/* out/tre1ocen.out )

_id=${PWD##*/}

if [ ! -d "../../tutorial/$_id" ]; then
    mkdir -v ../../tutorial/$_id
fi

for _file in "${_files[@]}"; do
    cp -v $_file ../../tutorial/$_id/$_file
done
