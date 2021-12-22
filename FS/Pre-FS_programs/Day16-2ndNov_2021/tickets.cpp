#include <iostream>
using namespace std;
// 25 25 50 50 100 ; 0
bool canSettleAmount(int money[], int numCustomers){
    int counterBalance = 0;
    
    for(int i=0; i<numCustomers; i++){
        if(money[i] == 25)              // if could settle it simply..
            counterBalance += money[i];  // += 25;
        else if(counterBalance >= money[i]-25){  // as to return atleast 25 to the >25 ticket..
            if(money[i] == 50)
                counterBalance -= 25;
            else if (money[i] == 100)
                counterBalance -= 75;
            else{
                cout << "inside";
                return false;
            }
            // could able to give.. so we get 25.. (as rest settled)..
            counterBalance += 25;
        }
        else{
            cout << "outside" << endl;
            return false;
        }
        cout << counterBalance << "("<<i<<")" <<endl;
    }
    // comes to here, when could settle amount to all the customers..
    return true;
}

int main(){
    int numCustomers=0, tempMoney=0;
    cin >> numCustomers;
    int moneyReceived[numCustomers];
    for(int i=0; i<numCustomers; i++){
        cin >> tempMoney;
        moneyReceived[i] = tempMoney;
    }
    
    if (canSettleAmount(moneyReceived, numCustomers))
        cout << "true";
    else
        cout <<"false";
        
}