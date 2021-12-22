/*
if not of same length, return false.
if of same length:
    if they are alike:
        return false

    not exactly same
        are the count of chars same..??
            if not return..
        else
        need to make same
*/

#include<bits/stdc++.h>
using namespace std;
map <char, int> mapper1, mapper2;

bool validate(string str1, string str2){
    if(str1.length() != str2.length() || str1 == str2)
        return false;
    // control being here, tells that they are of same length..
    // Get the frequency of characters for each string..
    //map <char, int> mapper1, mapper2;
    for(int i=0; i<str1.length(); i++){
        mapper1[str1[i]]++;
        mapper2[str2[i]]++;
    }

    // Are their frequencies equal..??
    cout << "filled maps" << endl;
    /*if(mapper1 == mapper2)
        return true;
    else
        return false;*/
    return std::equal(mapper1.begin(), mapper1.end(), mapper2.begin());
}
set<char> set1, set2;
bool checker(string str1, string str2){
    //if(str1.length() != str2.length() || str1 == str2)
    //    return false;
    //set<char> set1, set2;
    for(int i=0; i<str1.length(); i++){
        set1.insert(str1[i]);
        set2.insert(str2[i]);
    }
    return set1 == set2;
}

bool matcher(string str1, string str2){
    
    if(str1.length() != str2.length())
        return false;
    // control stays here, if of equal length..
    else if (str1 == str2 ){
        set<char> set1, set2;
        for(int i=0; i<str1.length(); i++){
            set1.insert(str1[i]);
            set2.insert(str2[i]);
        }
        if(set1.size() == set2.size() && set1 == set2)  
            return true;
        else 
            return false;
    }
    else{
        int mismatchCounter=0;
        for(int i=0; i<str1.length(); i++)
            if(str1[i] != str2[i])
                mismatchCounter++;
        cout << "Hello world"<< endl;
        cout << mismatchCounter << endl;
        cout << checker(str1, str2);

        return mismatchCounter <= 2;
    }
}

int main(){
    string str1="", str2="";
    cin >> str1 >> str2;
    if(matcher(str1, str2))
        cout << "true";
    else    
        cout <<"falsef d";
}