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
        mkdir -vp -- "$_id/$_src"
    elif [[ -f "$_package/$_src" ]]; then
        cp $_package/$_src $_id/$_src
    else
        _warn "File format not supported."
    fi
done

mkdir -v $_id/in
touch $_id/in/${_id}0.in

mkdir -v $_id/out
touch $_id/out/${_id}0.out
