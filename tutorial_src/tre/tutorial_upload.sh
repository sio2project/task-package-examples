#!/bin/bash

set -e

# If you want to add whole directory you need to put * after dir name.
# Example: in/* .
_files=( doc/trezad.pdf prog/*.cpp prog/*.py in/* out/tre1ocen.out )

. ../package/copy_to_tutorial.sh
