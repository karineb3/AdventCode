#!/bin/bash

# Se déplace vers le chemin ou l'on veut output les commandes cmake/make 
# cd "$(dirname "$0")"/build

cmake -S ./ -B ./build/
make -C ./build/ VERBOSE=1
./build/parsingCalibrationDocument
make -C ./build/ clean