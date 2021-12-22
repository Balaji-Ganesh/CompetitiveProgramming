/*
Varun and Srujan are playing a word game. Srujan has given a word of length N 
and a character(ch) which exist in the word.
Now Varun's task is to find the smallest distance of the given character in the
word for each position in the word.

Help Varun to return an array result[] where result.length==N and result[i] is 
the smallest distance from the given character to index i in the word.

The distance between two indices i and j is abs(i - j) , where abs is the 
absolute value function.

Input Format:
-------------
Line-1: A string represents a word
Line-2: a character ch which exist in the word.
 
Output Format:
--------------
Print an array of N values
 
Constraints:
 1 <= word.length <= 10^4
word[i] and ch are lowercase English letters.
It is guaranteed that 'ch' occurs at least once in word .

 
Sample Input-1:
---------------
conclude
c
 
Sample Output-1:
----------------
0 1 1 0 1 2 3 4

 
Sample Input-2:
---------------
kmitngit
i

Sample Output-2:
----------------
2 1 0 1 2 1 0 1 

 
*/
#include <bits/stdc++.h>
using namespace std;

int findNearestIdx(int idx, vector<int> &indices){
    // ------------------------------------------- Check with two indices at a time, and pick the minimum.... -- WORK pending here...
    int min = INT_MAX;
    for(int i=0; i<indices.size(); i++){
        //min = INT_MAX;
        cout << "[INFO] diff: " << abs((indices[i]-idx)) << endl;
        if(abs((indices[i]-idx)) <= min)
            min = indices[i];
    }
    cout << "[INFO] " << "Returning: " << min <<" for "<<idx<< endl;
    return min;
}

vector<int> findDistances(string word, char letter){
    vector<int> indices;
    // Get all the indices, where the given letter appears..
    for(int idx=0; idx<word.length(); idx++)
        if (word[idx] == letter)
            indices.push_back(idx);
    
    for(auto element: indices)
        cout << element << "  ";
    cout << endl;
    
    // Fill the array.. with the nearest absolute distances..
    vector<int> arr(word.length(), 0); // It will be same size of the given word..
    for(int idx=0; idx<word.length(); idx++)
        if(word[idx] == letter)         // Skip filling for itself (any ways, its filled with 0, earlier ..)
            continue;
        else
            arr[idx] = abs(idx - findNearestIdx(idx, indices));
    //for(auto element: arr)
    //    cout << element << " ";
    
    return arr;
}


int main(){
    string word;
    char letter;
    cin >> word >> letter;
    for(int element: (findDistances(word, letter)))
        cout << element << " ";
}