/*
Raj and Bheem are using a Desktop Computer.One day they found that keyboard is 
defective in which if you type backspace button,it will print '$' , instead of 
removing one previous character.
Bheem and Raj have tried to type one word each on the same keyboard.
Return true, if both tried to type the same word.otherwise return false.

Note:backspace for an empty text will continue empty.

Input Format:
-------------
Line-1:Two space seperated strings represents words w1,w2.

 
Output Format:
--------------
Print a boolean result.
 
Constraints:

    1 <= w1.length, w2.length <= 200
    w1 and w2 only contain lowercase letters and '$' characters.


 
Sample Input-1:
---------------
pq$r  pt$r

Sample Output-1:
----------------
true

Explanation:
------------
Both wants to type 'pr'

Sample Input-2:
---------------
se$$at cea$$t

Sample Output-2:
----------------
false

Sample Input-3:
---------------
s$$at ce$$at

Sample Output-2:
----------------
true

Explanation:
------------
Both wants to type 'at'.

*/
import java.util.Scanner;

class keyboardChars{

    static boolean areBothEquivalent(String word1, String word2){
        // This function returns true, if both tried to enter the same word, else false..
        StringBuilder sb1 = new StringBuilder(word1);
        StringBuilder sb2 = new StringBuilder(word2);
        
        int idx1=-1, idx2=-1;
        while(((idx1 = sb1.indexOf("$")) != -1) || (idx2=sb2.indexOf("$"))!=-1){   // As long as we are done with dealing with erronous backspaces.. go on..
            if(idx1 != -1){
                if(idx1 == 0)
                    sb1.deleteCharAt(idx1);
                else
                    sb1.delete(idx1-1, idx1+1); // +1: as right bound is treated as )
                System.out.println("word1: "+sb1+" idx1: "+idx1);
            }
            if(idx2!=-1){
                if(idx2==0)
                    sb2.deleteCharAt(idx2);
                else
                    sb2.delete(idx2-1, idx2+1); // +1: as righbound is treated as )
                System.out.println("word2: "+sb2+", idx2: "+idx2);
                }

            // Expecting errors... -- what if entered backspaces without typing any char..            
        }
        System.out.println("word1: "+sb1+" idx1: "+idx1+", word2: "+sb2+", idx2: "+idx2);

        return sb1.toString().equals(sb2.toString());
    }

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        String word1 = scanner.next();
        String word2 = scanner.next();

        System.out.println(areBothEquivalent(word1, word2));
        scanner.close();    
    }
}

/**
 * 
 * Another approach..
 *  Use Stack....
 *      As and when we get a $, POP the TOS
 *      -- don't forget to handle the case of -- more dollars than the characters typed earlier..
 */