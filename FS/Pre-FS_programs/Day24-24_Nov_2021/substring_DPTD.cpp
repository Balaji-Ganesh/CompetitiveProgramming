/*
Nagesh has given two words to check whether the first word 'source' is a
sub-series of second word 'target'.

A sub-series from a word can be formed by removing 0 or more characters without 
changing the relative order of other characters in the word.

For example, 'nest' is a subseries of a word 'interst' , where as 'rest' is not.

Help Nagesh to return true if source is a subseries of target, otherwise false.

Constraints:
 0 <= source.length <= 100
 0 <= target.length <= 10^4
 source and target consist only of lowercase English letters.

Input Format:
-------------
Line-1:Two space separeted strings

 
Output Format:
--------------
Print a boolean result.
 
 
Sample Input-1:
---------------
pqsv pqrstuv
 
Sample Output-1:
----------------
true

Sample Input-2:
---------------
psr pqrst

Sample Output-2:
----------------
false

*/

#include <bits/stdc++.h>
using namespace std;
map<string, bool> mapper;
bool is_a_subsequence(string str1, string str2, int str1Len, int str2Len){
    if (str1Len==0)     // if could able to reach here... indicates that, we've covered it in searching this in str2..
        return true;        
    if (str2Len == 0)   // In process of  finding subsequence, we ended up at str2..
        return false;   //  means we couldn't find, so false..

    string key = to_string(str1Len) + "|"+to_string(str2Len);        // A way of storing, which helps in recognizing sub problem later..
    if(mapper[key]==false && str1[str1Len] == str2[str2Len])
        mapper[key] = is_a_subsequence(str1, str2, str1Len-1, str2Len-1);   // As matched, move the pointers ahead forward..
    else   
        mapper[key] = is_a_subsequence(str1, str2, str1Len, str2Len-1);                                 // As not matched, move only the str2's... expecting that will meet with one charcter in str1..
    return mapper[key];
}

int main(){
    string str1="", str2="";
    cin >> str1 >> str2;

    if(is_a_subsequence(str1, str2, str1.length(), str2.length()))
        cout << "true";
    else    
        cout <<"false";
}