"""
/*
Rohan is given a range of natural numbers, [start, end], both are inclusive. 
He has to find the count of special numbers in the given range.    

Special Number is identified as follows:
    - Convert each number to its binary form, and 
      count the number of 1's in the binary form.
    - It is considered as Special number, if the count is a prime number.

Your aim is to help Rohan to find count of special numbers in given range.

Input Format:
-------------
Line: 2 space seperated integers, start and end.
 
Output Format:
--------------
Print an integer result.
 

Sample Input-1:
---------------
11 15
 
Sample Output-1:
----------------
4
 
Explanation:
------------
11- 1011-(3 1's in binary, 3 is a prime number)
12- 1100-(2 1's in binary, 2 is a prime number)
13- 1101-(3 1's in binary, 3 is a prime number)
14- 1110-(3 1's in binary, 3 is a prime number)
15- 1111-(4 1's in binary, 4 is a not prime number)

 
Sample Input-2:
---------------
5 8

Sample Output-2:
----------------
3
 
Explanation:
------------
5- 101-(2 1's in binary, 2 is a prime number)
6- 110-(2 1's in binary, 2 is a prime number)
7- 111-(3 1's in binary, 3 is a prime number)
8- 1000-(1 1's in binary, 1 is not a prime number)

*/
"""

import math;

def isPrime(number):
    if number ==1:
        return False;
    for i in range(2, int(math.sqrt(number))+1):
        if number % i == 0:
            return False;
    
    return True;

def numSpecialNumbersIn(lower, upper):
    counter=0;
    for number in range(lower, upper+1):
        if isPrime(bin(number).count('1')):
            #print(number, end=", ")
            #print(bin(number).count('1'), isPrime(bin(number).count('1')))
            counter = counter+1
    
    return counter


def main():
    lower, upper = [int(num) for num in input().split()]
    print(numSpecialNumbersIn(lower, upper));
    #print(isPrime(int(input())));
main();