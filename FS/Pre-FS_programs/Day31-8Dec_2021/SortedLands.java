/*
Suvarna Bhoomi Infra developers made different plots on their ventures.All plots
in their lands are Squared in shape.You are given an array side[], where side[i]
is the side value of ith plot(0-indexed).

There are only two types of lands, Agricultural and Urban lands.To differentiate 
them, the side value of all plots in Urban land are represented with negative sign. 

The management wants to show the plot numbers to the customers in the 
non-decreasing order of their area. 

Your task is to help the Management to complete the task.

Note: The Input values in array side[] must be given in non-decreasing order.
 
Can u solve in O(n) complexity?

Input Format:
-------------
Line-1: An Integer N represents number of plots.
Line-2: N space separated integers represent side value of each plot.
  
Output Format:
--------------
 Print an array.

Constraints:
 1 <= N <= 10^4
 -10^4 <= side[i] <= 10^4
   
Sample Input-1:
---------------
5
-4 -2 1 3 5

  
Sample Output-1:
----------------
1 4 9 16 25 

Explanation:
------------
The area of each side is 16,4,1,9,25. So the sorted array is 1 4 9 16 25.
   
Sample Input-2:
---------------
4
-5 2 3 6
  
Sample Output-2:
----------------
4 9 25 36

Explanation:
------------
The area of each side is 25,4,9,36. So the sorted array is 4 9 25 36.

*/

import java.util.*;

class SortedLands{
/*
    static SortedSet<Integer> nonDecreasingAreas(int arr[]){
        SortedSet<Integer> set = new TreeSet<Integer>();
        for(int i=0; i<arr.length; i++)
            set.add(arr[i]*arr[i]);
        return set;
    }
*/
    static int[] nonDecreasingAreas_v1(int arr[]){
        int sortedLands [] = new int[arr.length];
        int leftIdx=0, rightIdx=arr.length-1;
        for(int idx=rightIdx; idx>= 0; idx--)
        //for(int idx=0; idx<=arr.length-1; idx++)
        // Start placing the higher elements... if filling from right, else - lower if from left... (choose apropriate loops for "left" or "right")
            if(Math.abs(arr[leftIdx]) <  Math.abs(arr[rightIdx]))   // play with < and >
                sortedLands[idx] = arr[rightIdx] * arr[rightIdx--];
            else
                sortedLands[idx] = arr[leftIdx] * arr[leftIdx++];
            
        return sortedLands;
    }
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        int landSides[] = new int[length];
        for(int i=0; i<length; i++)
            landSides[i] = scanner.nextInt();
        
        for(int element: nonDecreasingAreas_v1(landSides))
            System.out.print(element+" ");
        
        scanner.close();
    }
}