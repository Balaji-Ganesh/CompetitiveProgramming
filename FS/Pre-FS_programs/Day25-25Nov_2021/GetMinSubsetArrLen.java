/*Get the length from the max occurance of a number from list
Form all the subsets containing that 
*/
import java.util.*;

class GetMinSubsetArrLen{
    static int getMaxFreqNum(int arr[]){
        HashMap<Integer, Integer> frequencies = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> maxFreqs = new HashMap<Integer, Integer>();

        // Find the frequencies..
        for(int element: arr)
            frequencies.put(element, frequencies.getOrDefault(element, 0)+1);
        int maxFreq=Integer.MIN_VALUE, maxFreqVal=0;
        
        // Find the max freq value..        
        for(Map.Entry<Integer, Integer> entry: frequencies.entrySet())
            if(entry.getValue() >= maxFreq){
                maxFreq    = entry.getValue();
                maxFreqVal = entry.getKey();
            }
        System.out.println("[INFO] "+"Max freq value: "+maxFreqVal);
        return maxFreqVal;
    }

    static int getMinSubsetLen(int arr[], int maxOccurVal){
        int firstOccur_idx=0, lastOccur_idx=0;
        // Go forward...
        for(int i=0; i<arr.length; i++)
            if(arr[i] == maxOccurVal){
                firstOccur_idx = i;
                break;
            }
        // Go backwards..
        for(int i=arr.length-1; i>=0; i--)
            if(arr[i] == maxOccurVal){
                lastOccur_idx=i;
                break;
            }
            System.out.println("[INFO] "+"min length: "+(lastOccur_idx - firstOccur_idx+1));
        return lastOccur_idx - firstOccur_idx +1;
    }

    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int length = scanner.nextInt();
        int arr[] = new int[length];
        for(int i=0; i<length; i++)
            arr[i] = scanner.nextInt();
        scanner.close();
        
        System.out.println(getMinSubsetLen(arr, getMaxFreqNum(arr)));

    }
}