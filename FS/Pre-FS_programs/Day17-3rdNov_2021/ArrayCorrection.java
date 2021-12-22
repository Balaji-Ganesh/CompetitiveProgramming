/*
Given a number N, there is a machine which displays numbers from 1 to N in
random order.Due to some defect in the machine , it displayed a number twice 
and one number is missed.

You task is to return an array which consists the number got duplicated
and the missed number .

Input Format:
-------------
Line-1: An integer N represents size of the array.
Line-2: N space separated integers.
   
Output Format:
---------------
Print an array of 2 values.
  
Constraints:

    2 <= N <= 10^4
    1 <= a[i] <= 1000

  
Sample Input-1:
---------------
5
1 2 3 1 5
   
Sample Output-1:
----------------
1 4
  
  
Sample Input-2:
---------------
6
6 2 4 1 2 3
   
Sample Output-2:
----------------
2 5
*/

import java.util.*;

class ArrayCorrection{

    public static int[] correctArray(int[] list){
        int list_sum=0, set_sum=0;
        Set<Integer> elements = new HashSet<Integer>();
        for(int element: list){
            elements.add(element);
            list_sum+= element;
        }

        // Get the sum of the elements of set...
        for(int element: elements)
            set_sum += element;
        // Calculate the repeating element..
        int repeating_element = list_sum-set_sum;
        
        // Now, find the missed element..
        int missed_element = (list.length * (list.length+1))/2-set_sum;

        //System.out.println("total sum should be: "+(list.length * (list.length+1))+", "+list.length);
        int [] transport = {repeating_element, missed_element};
        return transport;
        
    }

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);

        int length = scanner.nextInt();
        int list[] = new int[length];
        for(int i=0; i<length; i++)
            list[i] = scanner.nextInt();
        
        //System.out.println(correctArray(list))
        int carriage[] = correctArray(list);
        for(int element: carriage)
            System.out.print(element+" ");
    }
}
