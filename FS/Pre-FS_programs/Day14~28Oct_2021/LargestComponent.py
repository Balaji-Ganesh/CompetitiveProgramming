"""
/*
There are N rail compartments and each compartment has an ID printed on it. 
Given an array of compartments where compartment[i] is the ID printed on i-th compartment.

There are 2 hooks for each compartment to connect with other compartment.
You need to form the rails by connecting the compartments with each other.
You can connect two compartments with each other if their IDs are consecutive.
e.g., consecutive numbers: 1,2,3,... or 5,6,7,8.

Your task is to find the length of the longest rail can be formed.

Input Format:
-------------
Line-1: An integer N represents number of compartments.
Line-2: N space separated integers, IDs of compartments.

   
Output Format:
---------------
Print an integer value
  
  
Sample Input-1:
---------------
7
12 6 5 10 11 7 8

Sample Output-2:
----------------
4

Explanation:
------------
The compartments with values 5,6,7,8 can be connected and 
the compartments with values 10,11,12 can be connected. 
So the rail with maximum length is 4.
  
  
Sample Input-2:
---------------
6
1 3 4 5 11 10
   
Sample Output-2:
----------------
3

Explanation:
------------
The compartments with values 3,4,5 can be connected and 
the compartments with values 10,11 can be connected. 
So the rail with maximum length is 3.
    
Constraints:
 0 <= N <= 10^5
 -10^9 <= b[i] <= 10^9

*/
"""

def find_root(parents, comparment):
    if parents[compartment] == [compartment]:
        return compartment
    return

def unionize():
    pass

def findLargestCompartment(compartments):
    

def main():
    num_compartments = int(input())
    comparments = list(map(int, input().split()))
    parents = {}
    
    # Fill the dictionary..
    for comparment in comparments:
        parents[compartment] =[compartment]
    
    
    print(findLargestCompartment(parents);
    
# Startr running..
main()