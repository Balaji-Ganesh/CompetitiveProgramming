#include <iostream>
using namespace std;

bool is_converse(int num){
	int prev=num%2;
	num = num/2;

	while(num >0)
	{
		if(num%2==0)
			if(prev==1)
				return false;
			else
				prev = 1;
		else
			if(prev==0)
				return false;
			else 
				prev = 0;
		num /= 2;
	}
	return true;
}

int main()
{
	int num;
	cin >> num;
	cout << is_converse(num);
}
