
# Place armor stands

execute if entity @s[scores={laby_maze=0}] run function laby:mazes/maze0
execute if entity @s[scores={laby_maze=1}] run function laby:mazes/maze1
execute if entity @s[scores={laby_maze=2}] run function laby:mazes/maze2
execute if entity @s[scores={laby_maze=3}] run function laby:mazes/maze3
execute if entity @s[scores={laby_maze=4}] run function laby:mazes/maze4
execute if entity @s[scores={laby_maze=5}] run function laby:mazes/maze5
execute if entity @s[scores={laby_maze=6}] run function laby:mazes/maze6
execute if entity @s[scores={laby_maze=7}] run function laby:mazes/maze7
execute if entity @s[scores={laby_maze=8}] run function laby:mazes/maze8
execute if entity @s[scores={laby_maze=9}] run function laby:mazes/maze9


# Place structure blocks

function laby:build/test


# Activate structures by powering the structure blocks

function laby:activatestruct


# Clean

function laby:killarmorstands
