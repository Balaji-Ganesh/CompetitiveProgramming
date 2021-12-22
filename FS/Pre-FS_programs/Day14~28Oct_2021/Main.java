import java.util.*;

class Main{
    
    public static float giveLargestAvgSublist(int list[], int sublistSize, int windowSum){
        int tempSum=windowSum, maxSum=windowSum;
        //float maxAvg=windowSum/sublistSize, tempAvg;
        System.out.println("Entering...");
        for(int i=1; i+sublistSize < list.length; i++){
            tempSum = tempSum+list[i+sublistSize]-list[i-1];
            System.out.println("\t"+list[i+sublistSize]);
            System.out.println(tempSum);
            if(tempSum  > maxSum)
                maxSum = tempSum;
            System.out.println(tempSum);
        }
        System.out.println("hello");
        
        return maxSum/sublistSize;
    }
    
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        int list[] = new int[length];
        for(int i=0; i<length; i++)
            list[i] = scanner.nextInt();
        int sublistSize = scanner.nextInt();
        int windowSum=0;
        for(int i=0; i<sublistSize; i++)
            windowSum += list[i];
        System.out.println("Going to compute.."+windowSum);
        System.out.println(giveLargestAvgSublist(list, sublistSize, windowSum));
    }   
}

/*
-3 -5 7 8 12 -10 -12

4 14 -8 -2 27 12
4
*/
