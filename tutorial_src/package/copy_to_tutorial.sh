#!/bin/bash

_id=${PWD##*/}
for file in "${_files[@]}"; do
    cp -v $_file ../../tutorial/$_id/$_file
done
