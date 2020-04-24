#!/bin/bash

declare -r PACKAGE="$(dirname -- "$0")/package"

if [[ ! -d "$PACKAGE" ]]; then
    echo "Package directory does not exist."
    exit 1
fi

if [[ $# -eq 1 ]]; then
    declare -r ID="$1"
else
    echo "Usage: $(basename -- "$0") short_name"
    exit 1
fi

# Check for '/' character in $ID.
if [[ "$ID" = */* ]]; then
    echo "ERROR: short_name can't have '/' character."
    exit 1
fi

# Fail if $ID exists and is not empty.
if [[ -e "$ID" && ! -z "$(ls -A "$ID")" ]]; then
    echo "Directory '$ID' exists and is not empty."
    exit 1
fi

for SRC in $(cd "$PACKAGE"; find .); do
    if [[ -d "$PACKAGE/$SRC" ]]; then
    # copy directory non-recursively
        mkdir -vp -- "$ID/$SRC"
    elif [[ -f "$PACKAGE/$SRC" ]]; then
        ln -rs $PACKAGE/$SRC $ID/$SRC
    else
    # other files
        echo "Niewspierany typ pliku '$PACKAGE/$SRC'."
    fi
done

# mkdir $ID
# mkdir $ID/doc
# mkdir $ID/in
# mkdir $ID/out
# mkdir $ID/prog
# ln -rs $PACKAGE/Makefile $ID/Makefile
# ln -rs $PACKAGE/prog/* $ID/prog/
# ln -rs $PACKAGE/doc/Makefile $ID/doc/Makefile