#include <bits/stc++.h>
using namespace std;

int findWays(int numVarieties, int amount, int prices[], vector<<vector<int>>&dp){
	if(numVarieties == 0)
		return 0;
	if(amount == 0)			// indicates that, we found way of including it for making the price..
		return  1;
	if(dp[numVarieties][amount] != -1)					// If already calculated, use it --- Memoization..
		return dp[i][j];

	/// If not already calculated.. do it.,.
	if(prices[numVarieties][amount] >= amount)
		dp[numVarieties][amount]	= findWays(numVarieties, amount-prices[numVarieties][amount], prices, dp)
													+
								  findWays(numVarieties, amount, prices, dp);
	else
		dp[numVarieties][amount] = findWays(numVarieties, amount, prices, dp);

	return dp[numVarieties][amount];
}

int main(){
	int numVarieties=0, amount=0;
	cin >> numVarieties >> amount;
	int arr[numVarieties]={};
	for(int idx=0; idx<numVarieties; idx++)
		cin >> arr[idx];

	vector<<vector<int>> dp = new vector()
}