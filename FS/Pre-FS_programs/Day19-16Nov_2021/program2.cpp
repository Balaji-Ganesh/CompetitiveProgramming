/*
There are n boxes in a row. row[i] is the number printed on ith box(0-indexed).
Your task is to find the smallest index  I of the row, 
where row[I] equals to the remainder when you divide I with 10.

If no such index found, print -1.

Constraints:
    1 <= n <= 100
    0 <= row[i] <= 9
Input Format:
-------------
Line-1: An integer n, number of boxes.
Line-2: n space separated integers represent numbers printed on the boxes
in the row.
 
Output Format:
--------------
Print an integer, smallest index possible.
 
 
Sample Input-1:
---------------
5
2 1 2 3 5
 
Sample Output-1:
----------------
1
 
Sample Input-2:
---------------
5
4 3 1 5 2

Sample Output-2:
----------------
-1*/

#include <iostream>
using namespace std;

int findSmallest(int array[], int length){
    // Check-1...
    for(int i=0; i<length; i++)
        if(array[i] == array[i]%10      )
            continue;
        else   
            return -1;
    cout << "Check-1 passed..!!" << endl;
    // Check-2... control comes here only if passed check-1...
    for(int i=0; i<length; i++)   
        if(array[i] == i)
            return i;
    return -1;
}

int main()
{
    int length=0, temp=0;
    cin >> length;
    int array[length]={0};
    for(int i=0; i<length; i++){
        cin >> array[i];
    }

    cout << findSmallest(array, length);
}