/*
In a theatre, there are N people stand in a line for tickets, 
male represented with 1 and female represented with 0.
 
Theater management decides to issue the tickets in such a way that
if one ticket issued to a male, next ticket should be issued to a female only, 
and vice versa.
 
In order to follow it, they planned to make few alterations in the line itself, 
so that no two adjacent persons have same gender.
  
You are given a binary string S, represents intial order of the people in the line.
In one alteration, you can replace one female '0' with a  male '1' or vice versa.
 
Your task to find and print the minimum number of alterations needed 
to make the line to follow alternate gender sequence.
 
Input Format:
-------------
A binary String, S.
 
Output Format:
--------------
Print an integer, minimum number of alterations.
 

Sample Input-1:
---------------
1001

Sample Output-1:
----------------
2

 
Sample Input-2:
---------------
101101
101011
 
Sample Output-2:
----------------
3
*/

import java.util.Scanner;

class alternator{

    public static int countFlipsForAlternating(String input){
        int counter1=0, counter2=0;
        for(int idx=0; idx<input.length(); idx++){
            System.out.println("[INFO] character: ("+idx+") "+input.charAt(idx));
            if(input.charAt(idx) == '0' && idx%2==1){
                counter1++;                             // runs for even nums
                System.out.println("[INFO] 0: "+input.charAt(idx));
            }
            if(input.charAt(idx) == '1' && idx%2==0) {  
                counter2++;                             // runs for odd nums..
                System.out.println("[INFO] 1:"+input.charAt(idx));
            }
        }
        System.out.println(counter1+" " + counter2);
        return counter1 > counter2 ? counter2 : counter1;
    }

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        String input    = scanner.next();

        System.out.println(countFlipsForAlternating(input));
    }
}