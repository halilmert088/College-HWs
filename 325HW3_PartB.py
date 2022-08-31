# Halil Mert CEYLAN
# 18243510049

import random
import math

mylist = []
center = (0, 0)
i = 0

def append():
    return mylist.append((random.randint(0,9), random.randint(0,9)))

map (append, range(10))

def distance_calc (tuple1, tuple2):
    return math.sqrt( ( pow(tuple1[0], 2) - pow(tuple2[0], 2) ) + ( pow(tuple1[1], 2) - pow(tuple2[1], 2) ) )

def score_calc (distance):
    if distance >= 0 and distance <= 3:
        return 10
    if distance >= 4 and distance <= 7:
        return 5
    if distance >= 8 and distance <= 11:
        return 3
    if distance > 11:
        return 0


def dartgame ():
    print("Hit point is: ", mylist[i])
    print("Center is: ", center)

    dist = float(distance_calc (mylist[i], center))

    print("The distance is: ", dist)

    if int(dist) > 11:
        print("Result: False\nOutside of the dart board!")
        print("------------------------------------")
    
    else:
        print("Result = True\nHit the board!")
        print("Score: ", score_calc(int(dist)))
        print("------------------------------------")

map (dartgame, mylist)
