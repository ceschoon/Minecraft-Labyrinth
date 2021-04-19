#! /bin/bash

num_mazes=$1

mkdir -p mazes
cd mazes

for (( i=0; i<$num_mazes; i++ ))
do
	echo "Generating maze number $i"
	../generate_maze 15 15
	../mcfunction_maze maze.dat 5 maze$i
	rm maze.dat
	rm maze_topo.dat
done
