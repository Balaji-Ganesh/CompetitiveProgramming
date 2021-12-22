/*
 * *
Vihan is given a number N and He wants to check whether N is a converse number
or not. 
The binary form of number N is said to be converse number, if it obeys 
the following property: "every pair of adjacent digits are different". 
Your task is to help Vihan to find N is a converse number or not.
If yes, print 'true', otherwise print 'false'.

 Input Format:
 -------------
 An integer N, the positive number.

Output Format:
--------------
Print a boolean result.

 Sample Input-1:
 ---------------
 85

 Sample Output-1:
 ----------------
 true
  
 Explanation:
 ------------
 Binary Rep of 85 is 1010101 
 
 Sample Input-2:
 ---------------
  87
  
 Sample Output-2:
 ----------------
  false
 
 Explanation:
  ------------
 Binary Rep of 87 is 1010111

 *
 * */

#include <iostream>
using namespace std;

bool is_converse(int num){
    int prev = (num & 1);
    num = num >>1;

    while(num >0)
    {
        if(num & 1)
            if (prev == 1)
                return false; // If earlier too, its same, return false
            else
                prev = 1;   // here to can take, num&1, but as known ..hard coded
        else
            if(prev ==0)
                return false;  // If earlier too, its same, return false
            else
                prev = 0;  // here too
        num >>= 1;
    }
    return true;
}

int main()
{
    int num;
    cin >> num;
    if (is_converse(num))
        cout << "true";
    else
        cout << "false";

    return 0;
}
