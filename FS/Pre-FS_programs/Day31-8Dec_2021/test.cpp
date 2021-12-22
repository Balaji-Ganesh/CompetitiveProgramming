// C++ code to sort an array of integers
// with the help of single loop
#include<bits/stdc++.h>
using namespace std;

// Function for Sorting the array
// using a single loop
int *sortArrays(int arr[], int length)
{
	
	// Sorting using a single loop
	for (int j = 0; j < length - 1; j++)
	{
		// Checking the condition for two
		// simultaneous elements of the array
		if (arr[j] > arr[j + 1])
		{
			// Swapping the elements.
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			
			// updating the value of j = -1
			// so after getting updated for j++
			// in the loop it becomes 0 and
			// the loop begins from the start.
			j = -1;
		}
	}
	return arr;
}

// Driver code
int main()
{
	// Declaring an integer array of size 11.
	int arr[] = { 1, 2, 99, 9, 8,
				7, 6, 0, 5, 4, 3 };
				
	// Printing the original Array.
	int length = sizeof(arr)/sizeof(arr[0]);
	string str;
	for (int i: arr)
	{
		str += to_string(i)+" ";
	}
	cout<<"Original array: ["
					<< str << "]" << endl;
	
	// Sorting the array using a single loop
	int *arr1;
	arr1 = sortArrays(arr, length);
	
	// Printing the sorted array.
	string str1;
	for (int i = 0; i < length; i++)
	{
		str1 += to_string(arr1[i])+" ";
	}
	cout << "Sorted array: ["
					<< (str1) << "]";
}

// This code is contributed by Rajout-Ji
