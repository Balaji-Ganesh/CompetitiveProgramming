"""
/*
Charan is working on photoshop design in which he has to type a set of digits 
from left to right. Each digit(0-9) is defined with different units of space 
required and represented by an array sp[]. 

 For example, sp[0] is the space required for the digit '0', sp[1] is the space
 required for the digit[1], and so on..

Charan is trying to type the given digits in the same order which is given,across
several lines and each line can take atmost 50 units of space.

Given a set of digits as string, return an array ar[] which consists the
following two values.
	1.ar[0] is the number lines required.
	2.ar[1] is the units of space in the last line.

Input Format:
-------------
Line-1: 10 space seperated positive integers.
Line-2: A string str[] represents the set of digits.
 
Output Format:
--------------
Print two space seperated values.
 
Constraints:

    sp.length == 10
    2 <= sp[i] <= 20
    1 <= str.length <= 1000
    str contains only digits from 0 to 9.


 
Sample Input-1:
---------------
3 2 3 4 5 6 7 8 9 10
9345678123
 
Sample Output-1:
----------------
2 9

Explanation:
------------
9345678 can fit in line-1.
123  in line-2:
So 
Number of lines=2
Last line consits 123 with units 2+3+4=9
 
Sample Input-2:
---------------
3 2 3 4 5 6 7 8 9 10
99999267

Sample Output-2:
----------------
2 18

Explanation:
------------
99999 can fit in line-1.
267 in line-2:
So 
Number of lines=2
Last line consits 267 with units 3+7+8=18.
 
 
*/
"""
max_units = 50          # change it acc. to problem statement..
"""
mis understood the statement........
def printer(lst):
    num_lines_req=1         # As, will print atleast one line meeting < max_units..
    starter = 0             # holds the start index, when printing in new line..
    end, idx = 1, 0;
    #for idx in range(len(lst)):
    while end <= len(lst):
        while sum(lst[starter:idx] < max_units):
            idx+= 1
        starter = idx
        num_lines_req += 1
"""

def printer(spaces, number):
    """
    space_taken = 0;
    num_lines_req, break_idx = 1, 1
    for space_req in number:
        #space_taken += spaces[int(spaces_req)]
        if(space_taken + spaces[int(space_req)]) > max_units:
            space_taken     = 0
            num_lines_req  += 1
            break_idx       = space_req
        else:
            if sum(lst[break_idx:] < max_units):
                return num_lines_req+1, sum(lst[break_idx:])
            space_taken += spaces[int(spaces_req)]"""
    _sum, lines_req = 0, 0
    idx, endIdx = 0, 1
    while idx <= len(number)-1:
        if(_sum+spaces[int(number[idx])] > max_units):
            lines_req += 1
            _sum = 0
            #endIdx = idx

        _sum += spaces[int(number[idx])]            # Even handles the sum of last line..
        idx += 1
    
    return lines_req+1, _sum
    # Now, calculate t
    #leftOverSpaces = []
    #for idx in range(endIdx, len(number)):
    #    leftOverSpaces.append(spaces[int(number[idx])])
    

if __name__ == '__main__':
    #length = int(input())
    spaces = [int(num) for num in input().split()]
    number = input()
    print(printer(spaces, number))