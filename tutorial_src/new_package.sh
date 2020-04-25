#!/bin/bash

_warn() {
  echo >&2 "$*"
}

_die() {
  _warn "$*"
  exit 1
}

declare -r _package="$(dirname -- "$0")/package"

if [[ ! -d "$_package" ]]; then
    _die "Package directory does not exist."
fi

if [[ $# -eq 1 ]]; then
    declare -r _id="$1"
else
    _die "Usage: $(basename -- "$0") short_name"
fi

# Check for '/' character in $ID.
if [[ "$_id" = */* ]]; then
    _die "ERROR: short_name can't have '/' character."
fi

# Fail if $_id exists and is not empty.
if [[ -e "$_id" && ! -z "$(ls -A "$_id")" ]]; then
    _die "Directory '$_id' exists and is not empty."
fi

for _src in $(cd "$_package"; find .); do
    if [[ -d "$_package/$_src" ]]; then
        # Create directory.
        mkdir -vp -- "$_id/$_src"
    elif [[ -x "$_package/$_src" ]]; then
        echo "Skip executable $_package/$_src"
    elif [[ -f "$_package/$_src" ]]; then
        # Create symlink (to makefile or .h library).
        ln -rs $_package/$_src $_id/$_src
    else
        _warn "File format not supported."
    fi
done
