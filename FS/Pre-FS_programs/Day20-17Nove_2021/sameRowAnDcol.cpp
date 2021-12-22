/*
Mr.Suresh asked Mr.Ramesh to create a grid with set of words in such a way that 
if you read the word in i-th row and the word in i-th column should be equal.
Mr. Ramesh created the grid accordingly.
   
Now it’s your aim to check whether Mr.Ramesh’s grid has satisfied conditions 
given by Mr.Suresh.
   
If satisfied, print "true". Otherwise print "false"

Constraints:
-------------
N should be a positive integer.
0 < word[i].length <= N
word[i+1].length <= word[i].length
    
Input Format:
-------------
Line-1 -> an integer N, number of words
Line-2 -> N space separated words.
   
Output Format:
--------------
Print a boolean result.
   
Sample Input-1:
---------------
4
kmit made idol tell
  
Sample Output-1:
----------------
true
   
Explanation:
-------------
Given grid looks as follows:
k m i t
m a d e
i d o l
t e l l
if you read the words in every i-th row and i-th column,
both the words are same. so return true.
    
    
Sample Input-2:
---------------
5
abcde bcde cde de e
   
Sample Output-2:
----------------
true

*/
#include<bits/stdc++.h>
using namespace std;

string padIt(string str, int maxLength){
    //cout << "-----" << maxLength << endl;
    if(str.length() == maxLength)
        return str;

    for(int i=str.length(); i<maxLength; i++){
        str+="_";
        cout<<i << endl;
    }
    //cout << "--" << str << endl;
    return str;
}
bool areTheySame(string list[], int length, int maxLength){

    // padding the strings.. so as not to create trouble..
    //for(int i=0; i<length; i++){
    //    list[i] = padIt(list[i], maxLength);
    //    cout << list[i] << endl;
    //}

    // Check.. are they same in column and row wise..
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            cout << "for " << i << (list[i].length() != list[j].length());
            if(list[i][j] != list[j][i] && list[i].length() != list[j].length())        // Check s that condition... try out on paper.. makes sense..
                return false;
            
        }
    }
    return true;
}

int main(){
    int numWords = 0, maxLenWord=-1;
    cin >> numWords;
    string list[numWords], temp;
    for(int i =0; i<numWords; i++){
        cin >> temp;
        //cout << "--- LENGTH: "<< temp.length() << ", maxLen "<< maxLenWord << ", " << (temp.length() < maxLenWord) << endl;
        //maxLenWord = temp.length() > maxLenWord ? temp.length() : maxLenWord;
        //if(temp.length() > maxLenWord)
        //    maxLenWord=temp.length();
        list[i] = temp;
        
    }

    //cout << maxLenWord << endl;
    if(areTheySame(list, numWords, maxLenWord))
        cout << "true";
    else   
        cout << "false";
}