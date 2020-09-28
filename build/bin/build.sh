#!/bin/bash

cmake ..

make

bin=BacteriaEvolutionSimProject
printf "Executable file is made as $bin\n\n"

./BacteriaEvolutionSimProject

