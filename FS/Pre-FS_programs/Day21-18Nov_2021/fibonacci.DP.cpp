#include <bits/stdc++.h>
using namespace std;

void find_fibonacci_sequence_BU(int length){
    // bottom-up approach..
    int store[length];
    store[0] = 0;
    store[1] = 1;
    for(int i=2; i<length; i++)
        store[i] = store[i-1]+store[i-2];
    
    for(int i=0; i<length; i++)
        cout << store[i] << "  ";
}

map<int, int> store;
int helper(int n){
    if(store.find(n) == store.end())        // if not found..
        
}

void find_fibonacci_sequence_TD(int length, int idx){
    map<int, int> store;
    
}

int main(){
    int length=0;
    cout << "Length: ";
    cin >> length;
    find_fibonacci_sequence_BU(length);     cout << endl;
}