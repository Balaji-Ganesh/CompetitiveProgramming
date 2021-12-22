#include <bits/stdc++.h>
using namespace std;

vector<int> memoize;

int getLongestAscArrLen(int arr[], int idx, int len){
    if(len==0)      return 0;   //
    if(memoize[idx] != -1)      // If already solved, use it..
        return memoize[idx];
    else{
        int _max=0;
        for(int i=len-1; i>=0; i--){
            if(arr[i] < arr[len])
                _max = max(_max, getLongestAscArrLen(arr, idx+1, len)+1);
        }
        memoize[idx] = _max;
    }
    return memoize[len];
}

int main(){
    int length;
    cin >> length;

    int arr[length] = {0};
    for(int i=0; i<length; i++)
        cin >>arr[i];
    memoize.resize(length, -1);
    cout << getLongestAscArrLen(arr, 0, length-1]);
    for(int element: memoize)
        cout << element << "   ";
}