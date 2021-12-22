/*
Mr Somanath is a math teacher. He is given a problem to his students.
The students are given a number N, and the student has to perform following step:
       - Add each digit of the number and add the result to N
   Repeat this procedure until N becomes a single digit number.
    
 Your task is to help the students to perform the above steps and 
   print the resultant single digit number N.
    
    
    Input Format:
    -------------
    An integer, number N.
    
   Output Format:
   --------------
   Print an integer result.
    
    
   Sample Input-1:
   ---------------
    95
    
   Sample Output-1:
   ----------------
   5
   
   Explanation: 
   ------------
   95 => 9 + 5 = 14
   14 => 1 + 4 = 5
   Answer is 5
   
   
   Sample Input-2:
   ---------------
   765
   
   Sample Output-2:
   ----------------
    9
*/

#include <bits/stdc++.h>
using namespace std;

// Iterative Version..
int makeItOneDigit(int number){
    int temp=0, sum=0;
    while(1){
        sum=0;
        while(number >0){
            sum+=number%10;
            number/=10;
        }
        if(sum<10)
            return sum;
        else
            number = sum;
    }
}



// Recursive Fashion...
int makeItOneDigit(int number){
    int temp=0, sum=0;
    while(number >0){
        sum+=number%10;
        number/=10;
    }
    if(sum<10)
        return sum;
    else
        return makeItOneDigit(sum);
}

// An efficient version...
int makeItOneDigit(int number){
    int temp=0, sum=0;
    if (num == 0)
        return 0;
    else if (num %9==0)  // Handling mulitples of 9..
        return 9;
    else
        return num % 9;  // Any number by %9 gives its sum in 1digit
}
/*
+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+
 * */
