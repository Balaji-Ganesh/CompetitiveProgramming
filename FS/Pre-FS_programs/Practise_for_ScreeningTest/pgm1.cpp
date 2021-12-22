#include <bits/stdc++.h>
using namespace std;

bool isPresent(int element, int arr[], int start, int end){
    for(int i=start; i<=end; i++)
        if(arr[i] == element)
            return true;
    return false;
}

void getEatenLaddus(int laddusAte, int start, int end, int arr[]){
    //vector<pair<int, int>> missing;
    vector<int> missing;
    //int lower=0, upper=0;
    
    // Get all the missing elements..
    for(int val=start; val<=end; val++)
        if(isPresent(val, arr, start, end)== false)
            missing.push_back(val);

    for(int i=0; i<missing.size(); i++)
        cout << missing[i] << "    ";
    cout << endl;
    // Print the missing elements..
    cout << "[";
    int lower=-1, upper=-1;/*
    for(int idx=0; idx<missing.size(); ){
        lower = missing[idx];
        while(missing[idx+1] != missing[idx]+1){
        	idx++;
		}
		cout << "idx: " << idx << endl;
        upper = missing[idx+1];
        if(lower == upper)
            cout << lower<<", ";
        else
            cout << lower <<":"<<upper <<",";
    }
    cout << "]";*/
    cout << endl << endl;
    for(int idx=0; idx<missing.size()-1; idx++){
    	lower = missing[idx];
    	cout << lower;
		if(missing[idx+1] != lower+1){
			if(lower == missing[idx])
				cout <<", ";
			else
				cout << ":" << missing[idx+1] << ", ";
		}
			
	}
}   

int main(){
    int laddusAte=0, start=0, end=0;
    cin >> laddusAte >> start >> end;
    int len=end-start-laddusAte;
	int laddus[laddusAte];
    //cout << len << endl;
    for(int i=0; i<laddusAte; i++)
    	cin >> laddus[i];
    cout << "Done.." << endl;
    getEatenLaddus(laddusAte, start, end, laddus);
}
