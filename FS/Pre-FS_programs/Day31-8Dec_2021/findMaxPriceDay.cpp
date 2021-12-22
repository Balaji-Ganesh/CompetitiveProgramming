#include <bits/stdc++.h>
using namespace std;
// via pairs..- why failing..
/*
int findDayOfMaxPrices(vector<pair<int, int>> analysis){
    // sort it (based on price) ...
    sort(analysis.begin(), analysis.end());
    // Apply binary search..
    int leftIdx=0, rightIdx=analysis.size()-1, midIdx=0;
    while(leftIdx >= rightIdx){
        midIdx = leftIdx + (rightIdx-1)/2;
        int leftSide=analysis[midIdx-1].first, rightSide=analysis[midIdx+1].first, mid=analysis[midIdx].first;
        if(mid > leftSide && mid < rightSide)   
            //return analysis[midIdx].second;         // return the max..
            
            return analysis[midIdx].first;
        else if(mid < leftSide)
            rightIdx = midIdx-1;
        else
            leftIdx = midIdx+1;
    }

    //return (analysis[analysis.size()-1]).second();
}*/

int findDayOfMaxPrices(int prices[], int length){
    int leftIdx =  0, rightIdx = length-1, midIdx=0;
    while(leftIdx <= rightIdx){
        midIdx = (leftIdx + rightIdx)/2;
        //cout << "Calculated mid idx: "<< midIdx <<", leftIdx: " << leftIdx << ", rightIdx: "<< rightIdx << endl;
        if(prices[midIdx+1] < prices[midIdx] && prices[midIdx-1] < prices[midIdx]){
            //cout <<"Returning this value: " << prices[midIdx];
            //return prices[midIdx];
            return midIdx;
        }
        else if (prices[midIdx] < prices[midIdx+1])
            leftIdx = midIdx+1;
        else    
            rightIdx=midIdx-1;
    }
    
    //cout << "Hello bye" << endl;
    //return midIdx;
}

int main(){
    int totalDays=0, tempPrice=0;
    cin >> totalDays;
    int prices[totalDays]={};
  //  vector<pair<int, int>> analysis;
    //vector<int> prices;
    for(int day=0; day<totalDays; day++){
        //cin >> tempPrice;
        //analysis.push_back(make_pair(tempPrice, day));
        cin>> prices[day];
    }

    //cout <<analysis[1].first;

    //cout << findDayOfMaxPrices(analysis);
    cout << findDayOfMaxPrices(prices, totalDays);
}
/*
    If failed FS        benchmark
    1 - DSU/DP

*/