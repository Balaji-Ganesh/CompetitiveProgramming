/*
Amazon is conducting a drive online for eligible candidates. The candidate, who 
scores highest points in online test and his/her points are atleast two times 
greater than all other individual candidate's points, will be shortlisted 
directly to HR round.

Given an array of points  points[], return the index position of the shortlisted
candidate.If no one exist return -1.

Input Format:
-------------
Line-1: An integer n number of candidates.
Line-2: n space separated integers represent the points scored by each candidate.
 
Output Format:
--------------
Print an integer.
 
Constraints:
 1 <= n <= 500
 1 <= points[i] <= 100

 
Sample Input-1:
---------------
5
4 8 2 1 3
 
Sample Output-1:
----------------
1

Explanation:
------------
8 is two times greater than all other values.
 
Sample Input-2:
---------------
6
2 4 6 18 18 5

Sample Output-2:
----------------
-1

Explanation:
------------
No candidate selected for HR round.
 
*/

import java.util.*;

class AreAllTwiceLesserThanMax{

    static int areAllTwiceLesserThanMax(int arr[], int max, int maxIdx){
        for(int idx=0; idx<arr.length; idx++){
            if(idx != maxIdx)
                if(arr[idx]*2 <= max)
                    continue;
                else{
                    //System.out.println("At idx: "+idx);
                    return -1;
                }
        }
        return maxIdx;
    }

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        int arr[] = new int[length];
        int maxElement = Integer.MIN_VALUE, maxValIdx=-1;
        for(int idx=0; idx<length; idx++){
            arr[idx] = scanner.nextInt();
            if(arr[idx] > maxElement){
                maxElement = arr[idx];
                maxValIdx = idx;
            }
        }
        scanner.close();

        //System.out.println("MaxValue: "+maxElement+", idx: "+maxValIdx);
        System.out.print(areAllTwiceLesserThanMax(arr, maxElement, maxValIdx));
    }
}
/*
Other strategies:
    Sort and consider the largest and second largest..
*/