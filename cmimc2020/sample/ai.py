# Greed Control Starter File

# NOTE: You can run this file locally to test if your program is working.

#=============================================================================

# INPUT FORMAT: low, high, last

# low: The lowest possible integer you are allowed to submit
# high: The highest possible integer you are allowed to submit
# last: All submissions from the previous round, fixed by player order.
#   Your submission will be the first position.
#   On the first round, this list will contain all zeroes.

# Example input:

# low: 1
# high: 10
# last: [10, 10, 9, 8, 6]

#=============================================================================

# OUTPUT FORMAT:

# Invalid outputs will result in 0 being played (so no points will be gained).

#=============================================================================

# Write your bot in the greedy_bot class. Helper functions and standard
# library modules are allowed, and can be written before/inside these classes.

# You can define as many different strategies as you like, but only the class
# currently named "greedy_bot" will be run officially.


# Example greedy bot that plays the highest number every time:

import random

class greedy_bot:

	def __init__(self):
		pass
    
	def move(self, low, high, last):
		prob = []
		for k in range(low, high + 1):
			prob += [k]*k
		r = random.choice(prob)
		return r

#=============================================================================

# Local testing parameters

# If you would like to view a turn by turn game display while testing locally,
# set this parameter to True

LOCAL_VIEW = False

# Set a list of strategies you would like to test locally

LOCAL_STRATS = [
	greedy_bot(),
	greedy_bot(),
	greedy_bot(),
	greedy_bot(),
	greedy_bot(),
    ]

#=============================================================================












































# You don't need to change any code below this point

import json
import sys
import collections
import random

def WAIT():
    return json.loads(input())

def SEND(data):
    print(json.dumps(data), flush=True)

def ROUNDED(a):
    s=[]
    for i in a:
        s.append(f'{i:.2f}')
    return s

ROUNDS = 20

MASK = lambda a,i:[a[i]]+a[:i]+a[i+1:]

def PLAY(players):
    n = len(players)
    low = 1
    high = 10
    scores = [0]*n
    last = [0]*n
    for _ in range(ROUNDS):
        moves = []
        for i in range(n):
            try:
                move = players[i].move(low, high, MASK(last,i))
                if not (move == int(move) and low <= move <= high):
                    raise Exception("invalid move")
            except Exception as e:
                print(f"Player {i} has an error: {e}! Playing 0 instead.")
                move = 0
            moves.append(move)
        last = moves[:]
        tally = collections.Counter(moves)
        for i in range(n):
            scores[i] += moves[i]/tally[moves[i]]
        if LOCAL_VIEW:
            print("Plays this round:", ' '.join(map(str,moves)))
            print("Cumulative scores:", ' '.join(ROUNDED(scores)))
            input("Enter to continue (change LOCAL_VIEW to toggle this)")
    print("Final scores:", ' '.join(ROUNDED(scores)))
    if not LOCAL_VIEW:
        print("Change LOCAL_VIEW to True to see a turn by turn replay")
    
if len(sys.argv) < 2 or sys.argv[1] != 'REAL':
    PLAY(LOCAL_STRATS)
    input()

else:
    player = greedy_bot()
    while True:
        data = WAIT()
        play = player.move(data["low"],data["high"],data["last"])
        SEND(play)
