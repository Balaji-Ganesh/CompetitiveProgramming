"""
/*
A crew of N players played a game for one time, and got some scores.
They have to stand in the same positions after they played the game.
 
There is a constraint that, the player-K score, should not be greater or smaller
than both of his neighbors.
To achieve this constraint, there are few steps to be followed as mentioned:
    	- If the score of player-K is smaller than both his neighbors,then 
    	    his score is incremented.
    	- If the score of player-K is greater than both his neighbors,then 
    	    his score is decremented.
    	- The first and last elements never change.
    	Repeat these steps, until the constraint is satisified.
   
  Your task is to find and print the resultant array of scores, after the
  constraint is achieved.
   
NOTE: Players are not allowed to swap their positions to achieve the constraint.
  
Input Format:
-------------
Line-1: An integer N, number of players.
Line-2: N space separated integers represemts scores of each player.
  
Output Format:
--------------
Print integer array, the resultant scores.
   
Sample Input-1:
---------------
6
4 3 5 2 6 3
Sample Output-1:
----------------
[4, 4, 4, 4, 4, 3]
   
Sample Input-2:
---------------
8
5 1 4 2 7 4 6 3
Sample Output-2:
----------------
[5, 3, 3, 3, 5, 5, 5, 3]
*/
"""
def solve(original):
	copy = original.copy()

	#for idx in range(1, len(original)):		# range considers the upper bound as exlclusive.. so last handled, 1- first handled..
	#	print(idx)

	for idx in range(1, len(original)-1):		# range considers the upper bound as exlclusive.. so last handled, 1- first handled..
		left, right = original[idx-1], original[idx+1]
		#print(idx)
		if(original[idx] < left and original[idx] < right):
			copy[idx] = copy[idx]+1
		if(original[idx] > left and original[idx] > right):
			copy[idx] = copy[idx]-1;
	
	#print(original)
	#print(copy)
	if original == copy:
		return copy
	return solve(copy.copy())

def main():
	length = int(input())
	array = [int(num) for num in  input().split()][:length]
	#print(array)

	for value in solve(array):
		print(value, end=" ")

main()