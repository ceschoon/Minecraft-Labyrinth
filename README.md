# Maze generation for vanilla Minecraft

## World demo

Download and place the folder **Labyrinth-demo** in your .minecraft/saves/. You will spawn near a wooden platform with commands blocks from which you can press buttons to select and generate mazes.
You can also play a little game where you search items in the maze.

## Customize your maze

A set of unit structures is left in the demo world for the player to use. You can modify these structures and save them using the structure blocks next to them.

This set of structures can be selected to generate the maze by setting the 
"laby_palette" scoreboard to -1. You can easily change the value of this scoreboard by pressing the "change palette" button on the wooden platform at spawn.

## Source code

The functions used to generate these mazes belong to a datapack which is located at

> Labyrinth-demo/datapacks/Cedric_Labyrinth

The code development prior to the creation of this demo world is in the history of the repository

> https://github.com/ceschoon/Minecraft-Datapacks

## How it works

All the code for the maze generation is located in the Cedric\_Labyrinth datapack. The mazes are pre-generated using c++ code and stored in a text file. Another c++ code then converts the generated maze to a minecraft function (mazeX.mcfunction) containing commands to summon invisible armor stands. The armor stands mark the positions in the minecraft world where each unit cell of the maze must be build.

The building process is done by other minecraft function in three steps. The goal is to load a pre-generated unit structure at each armor stand position. All of these unit structure put together form the final maze we want to end up with.

The first step is to place structure blocks at the positions of the armor stands. To do so in a correct manner each armor stand is named with the identifier code of the structure that must be placed at its position. The second step is simply to activate the structure blocks by placing a redstone block on top of them. The third and last step consist in clearing the maze of all the armor stands that served as a position marker.

All of this is encapsulated in the laby:generate minecraft function (placement of the armor stands and building process). The maze to generate can be selected by changing the value of the "laby\_maze" scoreboard. The same way you can select the set of unit structures to be used by changing the scoreboard "laby\_palette".

## Gallery

![alt text](gallery/screenshot1.png?raw=true)
![alt text](gallery/screenshot2.png?raw=true)
![alt text](gallery/screenshot3.png?raw=true)
![alt text](gallery/screenshot21.png?raw=true)
