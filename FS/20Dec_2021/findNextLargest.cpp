/*
Kiran Rao purchased two boxes (Box1,Box2) of unique weights of gold coins, where first box weights are subset of second box gold weights.

 Now design a method for Gumadi Baleshwar Rao to find all the next largest weights 
of Box1 gold coins in the corresponding locations of box2 , 
if doesn’t exist return -1.

The Next largest Weight is Weight ‘W’ in Box1 is the first largest weight 
 to its right side weight in Box2.

NOTE: Unique weights means, no two coins will have same weight.

 Input Format:
 -------------
Line-1: space separated integers, weihts of gold coins in the first box.
Line-2: space separated integers, weihts of gold coins in the second box.

Output Format:
--------------
 Print a list of integers, next largest weights

Sample Input-1:
---------------
 4 3 2
 1 3 4 2

Sample Output-1:
 ----------------
 [-1, 4, -1]


 Sample Input-2:
 ---------------
5 6 3 4
1 5 3 7 8 6 4 2

 Sample Output-2:
 ----------------
[7, -1, 7, -1]
*/
#include <bits/stdc++.h>
using namespace std;

bool comparator(int a, int b){
    return a<b;
}

vector<int> finder(vector<int> &bag1, vector<int> &bag2){
    vector<int> result(bag1.size(), -1);        // fill with -1..
    for(int i=0; i<bag1.size(); i++){
        auto iter = find(bag2.begin(), bag2.end(), bag1[i]);        // Find where it in bag2.. as unique.. fine..
        //cout << "INFO" << bag1[i] << " found at " << iter-bag2.begin() << endl;
        cout << iter-bag2.end();
        if(iter != bag2.end())
            //cout << *max_element(iter-bag2.begin(), bag2.end(), comparator);  // idx: iter-v.begin()
            result[i] =  *max_element(bag2.begin()+(iter-bag2.begin()), bag2.end());
    }
    return result;
}

int main(){
    vector<int> bag1;
    vector<int> bag2;
    string line;
    int num;
    // Get t he first bag weights..
    getline(cin, line);
    stringstream stream(line);
    while(stream >> num)
        bag1.push_back(num);
    
    // Get the second bag weights..
    getline(cin, line);
    stream << line;
    while(stream>> num)
        bag2.push_back(num);
    //cout << find(bag2.begin(), bag2.end(), 7);
    for(auto &element: finder(bag1, bag2))
        cout << element << " ";

        cout << *max_element(bag1.begin(), bag1.end());
}

/*
    Code is still incomplete..
*/

/*
    Idea:
        find the index of element from bag1 in bag2..
        Perform search for finding the max from that obtained index to the end of bag2..
        -- repeat for all
*/