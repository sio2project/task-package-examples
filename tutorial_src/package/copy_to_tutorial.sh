#!/bin/bash

ID=${PWD##*/}
for FILE in "${FILES[@]}"; do
    cp -v $FILE ../../tutorial/$ID/$FILE
done
