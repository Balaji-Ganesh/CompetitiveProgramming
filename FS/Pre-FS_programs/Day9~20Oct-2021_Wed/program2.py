"""
/*
There is a series of bulbs in which some bulbs are turned on(indicated by 1) 
 and others are off(indicated by 0). 
 
A contiguous sub-series of bulbs CSB with following rules.
 1. Number of bulbs with status as 'on' and 'off' are same.
 2. Bulbs which are 'on' and 'off' are grouped together.
 You will be given the series as a string of 1's and 0's.
 Your task is to find the count of all the CSBs  exist in the given series.
 
 Input Format:
 -------------
 A string, indicates bulbs series.

 Output Format:
 Print an integer result.

 Sample Input-1:
 ---------------
 0 1 2 3 4 5 6 7 8 9 1 0
 0 1 0 0 1 1 0 0 0 1 1 0
 ---   ---       ---        : 01
   ---    ----       ---    : 10
     -------   -------      : 0011
         -------            : 1100
 
  
 Sample Output-1:
 ----------------
  9
 
 Explanation:
 ------------
 01-3, 10-3, 0011-2, 1100-1 

 Sample Input-2:
 ---------------
 0 1 0 1 0 1 0 
 --- --- ---    : 01
   --- --- ---  : 10

 
 Sample Output-2:
 ----------------
 6
 
 Explanation:
 ------------
 01-3, 10-3
*/
"""

word = input()
num_ones = word.count('1')
counter = 0

while(num_ones > 0):
    pattern = '1'*num_ones + '0'*num_ones;
    counter += word.count(pattern) + word.count(pattern[::-1])
    num_ones = num_ones-1

print(counter)

# Idea of approach by: Akhil VSS Gorugantu
"""
+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+
"""
