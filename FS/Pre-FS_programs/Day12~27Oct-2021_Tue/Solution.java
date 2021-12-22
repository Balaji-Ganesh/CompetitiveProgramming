import java.util.*;

class Solution{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        ArrayList <Integer> factors = new ArrayList<Integer>();
        for(int i=1; i<=(number/2); i++)
            if (number%i == 0)
                factors.add(i);
        
        int m = factors.get((factors.size()/2));
        int n = number/m;
        System.out.println(m+" "+n);
    }
}
