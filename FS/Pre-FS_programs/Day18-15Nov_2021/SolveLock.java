/*
/*
Krishna manohar and Santosh are working on a military operation at Himachal
Pradesh. They are given an operation to defuse the bomb, and they have time 
falling short.
   
Their informer will provide them with a round-shape lock of length ‘L’,where
L number of integers on the lock and a clue ‘C’.
    
To defuse the bomb they have to restore the original state of the lock,by 
restoring every integer on lock. All the integers must be restored in the same
way based on the clue.
  
Its your task to help Krishna manohar, to restore the original code on the lock,
to defuse the bomb.
 
To restore the lock to its original state, you have to follow these instructions:
 	- If C > 0, restore every i-th number with the sum of the next C integers.
    	- If C < 0, restore every i-th number with the sum of the previous
    	  C integers.
   	- If C == 0, restore every i-th number with 0.
   	
As the lock is in round shpae, the next element of lock[n-1] is lock[0], 
and the previous element of lock[0] is lock[n-1].
  
Input Format:
-------------
Line-1: Two space separated integers L, C.
Line-2: L space separated integers, integers on the Lock.
  
Output Format:
--------------
 Print the original state of the lock.
   
 Sample Input-1:
 ---------------
5 2
2 5 9 4 7
  
 Sample Output-1:
 ----------------
 [14, 13, 11, 9, 7]
   
 Sample Input-2:
 ---------------
 5 0
 1 5 6 3 2
  
 Sample Output-2:
 ----------------
 [0, 0, 0, 0, 0]

*/

import java.util.Scanner;

class SolveLock{

    //public static int get

    public static int[] solveLock(int lock[], int clue, int step){
        int moveIdx=lock.length;
        for(int idx=0; idx<lock.length; idx++){
            int tempSum=0;
            for(int j=0; j<clue; j++){
                moveIdx = (moveIdx+step+j)%lock.length;
                tempSum += lock[moveIdx];
                System.out.print(moveIdx + ", ");
            }
            //moveIdx = step>0? moveIdx-1: moveIdx+step;
            //moveIdx = step>0?moveIdx-1:moveIdx+1;
            lock[idx] = tempSum;
            System.out.println("");
        }
        return lock;
    }

    public static void main(String [] args){
        int lockSize, clue;
        Scanner scanner = new Scanner (System.in);
        lockSize = scanner.nextInt();
        clue     = scanner.nextInt();
        int lock[] = new int[lockSize];
        for(int i=0; i<lockSize; i++)
            lock[i] = scanner.nextInt();
        
        if(clue !=0)
            for(int lockValue: solveLock(lock, clue >0? clue: -clue, clue > 0 ? 1 : -1))
                System.out.print(lockValue + " ");
        else                                // Handling the case, if clue==0
            for(int i=0; i<lockSize; i++)
                System.out.print("0 ");
    }
}