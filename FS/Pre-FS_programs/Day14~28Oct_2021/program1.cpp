/*
There are two different colored balls in a box, either 'red' or 'blue' in color.
Red color balls are indicated with 1 and Blue color balls are indiacted with 2.
 
All the balls are placed in a row in random order, 
Your task is to find the largest consecutive set of blue colored balls
in the row and print the length of it.
 
 
 Input Format:
 -------------
 Line-1: An integer N represents the number of balls.
 Line-2: N Space seperated integers, only 1's and 2's
   
 Output Format:
 --------------
 Print an integer result.
  
   
 Sample Input-1:
 ---------------
8
2 2 2 1 2 2 1 1
   
 Sample Output-1:
 ----------------
3
   
   
 Sample Input-2:
 ---------------
10
1 2 2 1 2 1 2 2 1 2
   
 Sample Output-2:
 ----------------
 2
*/
// Need to count only """blue""", but also did for red too..
// So, it can be even optimized..
#include <bits/stdc++.h>
using namespace std;

int findLargestConsecutive(vector<int>&list){
    bool is_red=list[0]==1?true:false;                      // red: 1(true), blue: 2(false)
    int consecutiveLarge_count, temp_count=0;
    for(int number: list){
        if(number == 1 && is_red==true){                    // expecting a red one..
            temp_count++;
            is_red=true;
        }
        else if(number == 2 && is_red==false){              // expecting a blue one..
            temp_count++;
            is_red=false;
        }
        else{    /// Handles the new occurent ones...(w.r.t. previous occurance)
            if(temp_count > consecutiveLarge_count)         // only if got the higher count, get it..
                consecutiveLarge_count = temp_count;
            temp_count=1;                                   // reset to one.. as we got the different ball
            is_red = number==1?true:false;                  // Tracking,.. which ball has occured now... for further reference..S
        }
    }
    
    return consecutiveLarge_count;
}

int main(){
    vector<int> list;
    int length, temp;
    cin >> length;
    for(int i=0; i<length; i++){
        cin >> temp;
        list.push_back(temp);
    }
    
    cout << findLargestConsecutive(list);
}
