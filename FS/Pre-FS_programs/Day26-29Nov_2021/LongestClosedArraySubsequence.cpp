/*
An array ar[] is called as closed array when we subtract the largest and smallest 
element in the array,the result is equal to 1.

Your task is to return the length of its greatest closed subsequence among all
its possible subsequences.

A subsequence of array is a sequence that can be taken from the array by removing 
some or no elements without changing the order of the remaining elements.

Input Format:
-------------
Line-1: An integer n number of elements.
Line-2: n space separated integers represent the elements.
 
Output Format:
--------------
Print an integer.
 
Constraints:
 1 <= n <= 10^4
 -10^4 <= ar[i] <= 10^4

 
Sample Input-1:
---------------
6
4 3 5 2 6 3
 
Sample Output-1:
----------------
3

Explanation:
------------
Subsequence is [4,3,3]
 
Sample Input-2:
---------------
7
20 19 19 29 37 35 19

Sample Output-2:
----------------
4

Explanation:
------------
Subsequence is [20 19 19 19]
 
*/
#include <bits/stdc++.h>
using namespace std;

int getLongestSubseqLen(int  arr[], int len){
    map<int, int> freq;
    for(int idx=0; idx<len; idx++)  
        freq[arr[idx]] ++;
    
    int maxSubseqLen=INT_MIN, tempLen=0;
    for(int i=0; i<len; i++){
        //tempLen = freq[arr[i]];
        if(freq[arr[i]+1] != 0)             // If its consecutive predessor is present.. add its freq..
            tempLen = max(tempLen, max(freq[arr[i]], freq[arr[i]+1]+freq[arr[i]]));
        //if(freq[arr[i]-1] !=0 )             //                    successor 
        //    tempLen += freq[arr[i]-1];
        //if(tempLen > maxSubseqLen)
        //    maxSubseqLen = tempLen;
    }
    return tempLen;
}

int main(){
    int length=0;
    cin>> length;
    int arr[length];
    for(int idx=0; idx<length; idx++) cin >> arr[idx];

    cout << getLongestSubseqLen(arr, length);
}
