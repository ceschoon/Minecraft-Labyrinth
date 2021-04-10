# Create teams
team remove team1
team remove team2
team add team1 "Green"
team add team2 "Red"
team modify team1 color green
team modify team2 color red

# Temporary team for player not assigned in teams to fill
team remove noteam
team add noteam
team join noteam @a

# Fill teams (up to 10 players)
execute as @r[team=noteam] run team join team1 @s
execute as @r[team=noteam] run team join team2 @s
execute as @r[team=noteam] run team join team1 @s
execute as @r[team=noteam] run team join team2 @s
execute as @r[team=noteam] run team join team1 @s
execute as @r[team=noteam] run team join team2 @s
execute as @r[team=noteam] run team join team1 @s
execute as @r[team=noteam] run team join team2 @s
execute as @r[team=noteam] run team join team1 @s
execute as @r[team=noteam] run team join team2 @s
execute as @r[team=noteam] run team join team1 @s
execute as @r[team=noteam] run team join team2 @s
