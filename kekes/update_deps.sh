#!/bin/bash 
set -e

echo "Current time: $(date +"%Y-%m-%d %H:%M:%S")"

python3 -m venv tmpEnv

source ./tmpEnv/bin/activate

pip --version

#check venv is active
if [[ "$VIRTUAL_ENV" == "" ]]; then
    echo "Virtual environment is not active. Exiting."
    exit 1
fi 

#pip install --upgrade pip

pip install conan==2.10.3

DEPS_DIR=./deps/
CONF="Debug"

conan install $DEPS_DIR --build=missing -s build_type=$CONF -of build/$CONF --profile:build=${DEPS_DIR}${CONF}_prf --profile:host=${DEPS_DIR}${CONF}_prf

echo "Current time: $(date +"%Y-%m-%d %H:%M:%S")"