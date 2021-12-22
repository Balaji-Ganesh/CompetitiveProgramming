/*
Mr. James professor at MIT, as a part of assignment he created a
problem statement related to words.
He gave a word w and asked them to design a method to 
return the longest substring w1 in word w, where w1 in reverse is also equal to w1 -- palindrom in simple.

NOTE: Alphabets are case sensitive ('A' and 'a' are not same).

Input Format:
-------------
A string S, consist of lowercase/uppercase letters or/and digits

Output Format:
--------------
Print a string.


Sample Input-1:
---------------
abbbabbcbbacdb

Sample Output-1:
----------------
abbcbba


Sample Input-2:
---------------
thedivideriswide

Sample Output-2:
----------------
edivide
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> dp;

bool is_palindromic(string word, int i, int j){
    // Base cases for recursion..
    if(i==j)                            // single character... its a palindrome..
        return true;
    else if(i == j+1 || j == i+1)            // two characters... YES if both same, else not..
        return word[i] == word[j];
    else{                               // if of more length..
        if( word[i] == word[j] && is_palindromic(word, ++i, --j) )      // when both extremes are same, and inside is palindrome..
            return true;
        else if(is_palindromic(word, i+1, j) || is_palindromic(word, i, j-1))
            return true;
        else return false;
    }
}    


/*string get_LPS(string word, int i, int j){
    //dp = new bool[word.length()][word.length()];
    
}*/
int main(){
    string input;
    cin >> input;
    //get_LPS(input): // LPS: LongestPalindromicSubstring..
    //dp
    bool result = is_palindromic(input, 0, input.length()-1);
    cout << result;
}
