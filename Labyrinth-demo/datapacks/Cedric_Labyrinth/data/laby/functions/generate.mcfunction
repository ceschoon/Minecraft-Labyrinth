
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

scoreboard objectives remove laby_success
scoreboard objectives add laby_success dummy
scoreboard players set @s laby_success 0

execute if entity @s[scores={laby_palette=0}] store success score @s laby_success run function laby:build/build0
execute if entity @s[scores={laby_palette=1}] store success score @s laby_success run function laby:build/build1
execute if entity @s[scores={laby_palette=2}] store success score @s laby_success run function laby:build/build2
execute if entity @s[scores={laby_palette=3}] store success score @s laby_success run function laby:build/build3
execute if entity @s[scores={laby_palette=4}] store success score @s laby_success run function laby:build/build4
execute if entity @s[scores={laby_palette=5}] store success score @s laby_success run function laby:build/build5
execute if entity @s[scores={laby_palette=6}] store success score @s laby_success run function laby:build/build6
execute if entity @s[scores={laby_palette=7}] store success score @s laby_success run function laby:build/build7
execute if entity @s[scores={laby_palette=8}] store success score @s laby_success run function laby:build/build8
execute if entity @s[scores={laby_palette=9}] store success score @s laby_success run function laby:build/build9

execute if entity @s[scores={laby_success=0}] run tellraw @a [{"text":"[ERROR] Cannot build labyrinth using palette ","color":"gold"},{"score":{"name":"@a","objective":"laby_palette"}}]


# Activate structures by powering the structure blocks

execute if entity @s[scores={laby_success=1}] run function laby:activatestruct


# Clean

function laby:killarmorstands

scoreboard objectives remove laby_success

