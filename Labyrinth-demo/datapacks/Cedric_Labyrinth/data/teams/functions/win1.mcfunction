#team 1 wins

title @a title [{"text":"Green team won the game!","color":"green"}]
tellraw @a [{"text":"Green team won the game!","color":"green"}]

execute as @a at @s run playsound minecraft:entity.wither.spawn master @s ~ ~ ~
