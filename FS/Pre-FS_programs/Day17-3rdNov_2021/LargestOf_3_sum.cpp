/*
You are given a list of integers List[].
Your can choose any integers in List[] of size exactly 3 , such that the product
of the integers should be highest.
And print the highest value.
    
Input Format:
-------------
Line-1: An integer N represents size of the list.
Line-2: N space separated integers, List[]
   
Output Format:
---------------
Print an integer value
  
Constraints:

    3 <= N <= 10^4
    -1000 <= list[i] <= 1000

  
Sample Input-1:
---------------
5
1 2 -3 -4 5
   
Sample Output-1:
----------------
60
  
Explanation:
------------
The integers are -3,-4,5.
  
Sample Input-2:
---------------
6
-6 2 4 1 2 3
   
Sample Output-2:
----------------
24

Explanation:
------------
The integers are 4,3,2.
    
test cases..
4
2 -3 -4 5
output: 60

6
12 5 6 1 -1 3
360

10
86 87 96 26 -23 36 -8 55 -21 50
718272

6
40 54 6 36 82 -91
177120

3
-10 4 7

-- this test case is failing... try with a condition of if ==3..
*/

#include <bits/stdc++.h>
using namespace std;

int findLargest3Product(vector<int> values){
    /*
    // Place in set to sort..
    set<int> elements;
    for(int element: list)
        elements.insert(element);
    // place in the vector -- for ease of access
    vector<int>values(elements.begin(), elements.end());
    */
   if (values.size() == 3)
        return values[0]*values[1]*values[2];
   sort(values.begin(), values.end());
    int product1=0, product2=0, n=values.size()-1;
    if(values[0] < 0 && values[1] < 0)
        product1 = values[0] * values[1] * values[n];
    product2 = values[n] * values[n-1] * values[n-2];

    return product1>product2?product1 : product2;       // return the max..

}

int main(){
    int length, temp=0;
    vector<int> list;

    cin >> length;
    for(int i=0; i<length; i++){
        cin >> temp;
        list.push_back(temp);
    }

    cout << findLargest3Product(list);
}
/*
The case of 3 numbers, doesn't seems like a valid one... 
     it was updated after looking at the test cases..

+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+
*/