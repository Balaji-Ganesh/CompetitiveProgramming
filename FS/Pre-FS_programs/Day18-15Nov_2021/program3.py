"""
Naveen purchased two boxes (Box1,Box2) of unique weights 
of gold coins, where first box weights are subset of second box gold weights.
    
Now design a method for Naveen to find all the next largest weights of Box1 
gold coins in the corresponding locations of box2 , 
if doesn’t exist return -1.
   
The Next largest Weight is Weight ‘W’ in Box1 is the first largest weight 
to its right side weight in Box2.
   
NOTE: Unique weights means, no two coins will have same weight.
   
Input Format:
 -------------
 Line-1: Two integers represents size of box1 and size of box2.
 Line-2:space separated integers, weihts of gold coins in the first box.
 Line-3: space separated integers, weihts of gold coins in the second box.
   
Output Format:
--------------
Print a list of integers, next largest weights
    
Sample Input-1:
---------------
3 4
4 3 2
1 3 4 2
   
Sample Output-1:
----------------
 [-1, 4, -1]
   
Sample Input-2:
---------------
4 8 
5 6 3 4
1 5 3 7 8 6 4 2
   
Sample Output-2:
----------------
[7, -1, 7, -1]
"""
def solveWeights(box1, box2):
    mapper = {}
    for idx in range(len(box2)):
        nextHighestNum = -1
        for j in range(idx+1, len(box2)):
            if box2[idx] < box2[j]:            # If any highest number found after it..
                nextHighestNum = box2[j]
                break                       # to have only the next immediate highest
        mapper[box2[idx]] = nextHighestNum  # Store its nextHighestNumber (if present, else -1)
    
    result = []
    for weight in box1:
        result.append(mapper[weight]);      # Pulling out its next highestWeight in box2
    return result

def main():
    box1Len, box2Len = map(int, input().split())
    box1 = [int(num) for num in input().split()]
    box2 = [int(num) for num in input().split()]

    print(solveWeights(box1, box2))

main()