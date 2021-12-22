/*
You are given an array ar[] which consists only 2 types of values either 0 or 1.
The array is of size N (0-indexed).
You can form a binary array b[] of N binary numbers from the array ar[]. The ith 
binary number can be formed by selecting the contiguous values from 0-index to
i-1 index. 

For example: ar[]={1,1,0,1} then binary numbers are  b[0]=1, b[1]=3, b[2]=6 ,
b[3]=13.

Return a boolean array res[] where res[i]=true if b[i] is dvisible by 5.

Input Format:
-------------
Line-1: An Integer N represents size of the array.
Line-2: N space separated boolean values (0 or 1).
  
Output Format:
--------------
 Print a boolean array(true or false).
   
 Sample Input-1:
 ---------------
4
1 0 1 1 
  
Sample Output-1:
----------------
false false true false

Explanation:
------------
b[0]=1 =1 false
b[1]=10 =2 false
b[2]=101 =5 true
b[3]=1011=11 false
   
 Sample Input-2:
 ---------------
5
0 1 1 1 1
 Sample Output-2:
 ----------------
true false false false true 

Explanation:
------------
b[0]=0 =0 true
b[1]=01 =1 false
b[2]=011 =3 false
b[3]=0111=7 false
b[4]=01111=15 true

*/
#include <iostream>
#include <cmath>
using namespace std;

int binConvert(int arr[], int start, int end){
    int value=0, pwr=0;
    for(int idx=end; idx>=start; idx--)
        value += pow(2, pwr++)*arr[idx];
    //cout << endl << value << endl;
    return value;
}

void binPrefixesMod5(int arr[], int length){
    for(int i=0; i<length; i++)
    //    for(int j=0; j<=i; j++)
        if(binConvert(arr, 0, i) %5 == 0)
            cout<< "true ";
        else
            cout << "false ";
} 

int main(){
    int length=0;
    cin >> length;
    int arr[length];
    for(int idx=0; idx<length; idx++)
        cin >> arr[idx];

    //binPrefixesMod5(arr);
    //cout << binConvert(arr, 0, length-1);
    binPrefixesMod5(arr, length);
}