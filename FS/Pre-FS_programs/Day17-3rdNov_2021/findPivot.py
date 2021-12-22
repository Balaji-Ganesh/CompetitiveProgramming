"""
You are given a list of integers List[] of size N.
Your task is find a position p(0<=p<=N-1) in the List[], such that the addition
of all integers to the left of p should be exactly equal to addition of all the
integers to the right of p.
If all the integers are at one end of p ,assume the sum of other end is 0.
If there exist more than one answer , then return the leftmost p value.
if p doesn't exist, return -1.
    
Input Format:
-------------
Line-1: An integer N represents size of the list.
Line-2: N space separated integers, List[]
   
Output Format:
---------------
Print an integer result.
  
  
Sample Input-1:
---------------
5
10 2 3 4 3

Sample Output-1:
----------------
1

Explanation:
------------
p=1.
Left of p=10
Right of p=3+4+3=10.
  
  
Sample Input-2:
---------------
4
1 2 2 4

   
Sample Output-2:
----------------
-1

"""

def findPivot(lst):
    """
    worked... but not a recommended way..
    length = len(lst)
    if(sum(lst[1:])==0):        # for test case where right-side yields to 0 -- somme ambiguity here.. what if left..??     
        return 0
    for i in range(1, length):
        if sum(lst[0:i]) == sum(lst[i+1: length]):
            return i
    return -1"""
    total = sum(lst)
    leftSum = 0
    for i in range(len(lst)):
        if leftSum == total - leftSum - lst[i]:
            return i
        leftSum = leftSum + lst[i]
    return -1

def main():
    length = int(input())
    lst = list(map(int, input().split()))

    #print(*lst)
    print(findPivot(lst))
main()

"""
+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+
"""