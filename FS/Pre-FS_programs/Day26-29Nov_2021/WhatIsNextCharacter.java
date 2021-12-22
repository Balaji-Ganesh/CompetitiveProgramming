/*
Vishal has given a task to find the successor of a given alphabet 'alp' in a 
given string str[].

The alphabets in the given string str[] are all lowercase letters and always in 
non-decreasing order.

A successor of 'alp' is the next smallest alphabet exist in the string str[] 
which is greater than 'alp'.

Assume that alphabets can be considered in cyclic fashion.
For example: Successor for alp='z' in str[]="bcd" is 'b'.

Help Vishal to retunn the answer.

Can you solve it in O(log(n)) complexity?

Input Format:
-------------
Line-1:A string str[]
Line-2: a character represents an alphabet.
 
Output Format:
--------------
Print a character which is the successor.
 
Constraints:
 2 <= str.length<= 10^4
'alp' is a lowercase letter.

 
Sample Input-1:
---------------
adghijl
f 
Sample Output-1:
----------------
g

Sample Input-2:
---------------
abcdefghi
j

Sample Output-2:
----------------
a


adghfjkl
f
*/
import java.util.*;

class WhatIsNextCharacter{
    static char getNextCharacter(String str, char ch){
        char seq[] = str.toCharArray();
        Arrays.sort(seq);
        //System.out.println(seq);
        if(ch > seq[seq.length-1])      // for handling the array folding..
            return seq[0];
        else {                          // for other cases..
            int left=0, right=seq.length-1, mid=0, idx=0;
            while(left<=right){
                mid=(left+right)/2;
                //if(seq[mid] == ch)
                //    return seq[mid+1];
                if(ch < seq[mid]){
                    left = mid+1;
                    idx= mid;
                }
                else if(ch > seq[mid])
                    right = mid-1;
            }
            //System.out.println("Else case");
            // ------- O(n).... this is working with return seq[idx+1];
            // for(int i=1; i<seq.length-2; i++)
            //     if(ch >= seq[i-1] && ch <= seq[i+1])
            //         return seq[i+1];
        }
        return '-';
    }

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        String ch = scanner.next();

        System.out.println(getNextCharacter(str, ch.charAt(0)));
    }
}