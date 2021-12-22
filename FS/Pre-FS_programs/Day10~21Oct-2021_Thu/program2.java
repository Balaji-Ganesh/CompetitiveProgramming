import java.util.*;

class Solution{
    public static void main(String [] args){
        // Input section..
        Scanner scanner = new Scanner(System.in);
        int length=scanner.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        //ArrayList<Integer> prefix_max = new ArrayList<Integer>();
        int min_idx=0, min_val=Integer.MAX_VALUE, temp, max=0;//Integer.MIN_VALUE;
        
        for(int i=0; i<length; i++){
            temp = scanner.nextInt();
            list.add(temp);
            
            // Hold the min value..
            if(temp<min_val){
                min_val = temp;
                min_idx=i;
            }
            
            // Keep computing the prefix-arry_with_max
            //if(temp>max)
            //    max=temp;
        }
        
        for(int i=min_idx+1; i<length; i++)
            if(list.get(i) > max)
                max = list.get(i);
        
        if(max !=0 )                // If had some max price after buying.. sell it..
            System.out.println(max-min_val);
        else                        // If no higher price after buying, no profit..
            System.out.println(0);
    }
/*

+------------------------------+
|  8 tests run/ 7 tests passed |
+------------------------------+

Not handling the case of
4
4 7 1 2

Gives "1"
But need 3.

*/
