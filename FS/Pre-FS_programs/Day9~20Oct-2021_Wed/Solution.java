/**

/*
Rohan has a habit of writing a word in reverse as R and then checks whether
R is same as Original word W. If R is not same as W, he can remove only one
character from R to make it as W.
Print 'true', if Rohan makes R equals W, Otherwise print 'false'.

Input Format:
-------------
Line-1: A string represents a word.

Output Format:
--------------
return a boolean result.

Sample Input-1:
---------------
bcba

Sample Output-1:
----------------
true

Explanation:
------------
By removing charcter 'a', we will get the word in reverse is also same.

Sample Input-2:
---------------
abcd

Sample Output-2:
----------------
false

Explanation:
-------------
There is no possibility to make the reverse is also same.

*/

 */

import java.util.*;

class Solution{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        System.out.println(solve(word));
    }
    
    public static boolean solve(String word){
        StringBuilder sb = new StringBuilder(word);
        StringBuilder after = new StringBuilder();
        
        for(int idx=0; idx<word.length(); idx++)
        {
            after = sb.deleteCharAt(idx);
            if(after.toString().equals(after.reverse().toString()))
                return true;
            sb = new StringBuilder(word);  
        }     
        return false;
    }
}