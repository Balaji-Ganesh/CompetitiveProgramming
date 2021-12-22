/*
Sharath is playing a game where there are N levels. Inorder to win the game he 
has to reach Nth level.

The rule book explains "In one step you can either cross one level or two levels".

Return the number of distinct possible ways to win the game.

Constraints:

    1 <= N <= 45

Input Format:
-------------
Line-1: An Integer N represents number of levels.
  
Output Format:
--------------
Print an integer.


Sample Input-1:
---------------
2
  
Sample Output-1:
----------------
2

Explanation:
------------
1. 1-level+ 1-level =2
2. 2 levels in one step.
   
Sample Input-2:
---------------
4
  
Sample Output-2:
----------------
5

Explanation:
------------
1. 1-level + 1-level + 1-level + 1-level = 4
2. 1-level + 1-level + 2-levels = 4
3. 1-level + 2-levels + 1-level = 4
4. 2-levels + 1-level + 1-level = 4
5. 2-levels + 2-levels  = 4
*/

import java.util.*;

class Summer{
    public static HashMap<Integer, Integer> map;// = new HashMap<Integer, Integer>();
    // Classic recursive way...
    public static int crossLevel(int limit){
        if (limit == 1 || limit == 0)
            return 1;
        if(limit < 0)
            return 0;
        return crossLevel(limit-1)+crossLevel(limit-2);
    }
    public static int util(int limit){
        map = new HashMap<Integer, Integer>();
        map.put(0, 1);
        map.put(1, 1);
        //return map.get(0);
        return get_levels(limit);
        //return map.get(limit-1) + map.get(limit-2);
    } 
    public static int get_levels(int n){
        // Check whether solved already or not..
        //System.out.println("func: "+n+": "+map.get(n));
        if(n <2){
            //System.out.println("\tasdf"+map.get(n));
            return map.get(n);
        
        }
        if(map.get(n) != null){           // if already solInved..
            //System.out.println("In the map: "+map.get(n));
            return map.get(n);
        }
        //System.out.println("Before: "+map);
        map.put(n, (get_levels(n-1)+get_levels(n-2)));;
        //System.out.println("Test: "+(n-2)+": "+get_levels(n-2));
        //System.out.println("After: "+map);
        return map.get(n);
        //return 1;
    }
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int limit = scanner.nextInt();
        // via recursion,,
        //System.out.println("Number of ways: "+crossLevel(limit));
        // via DP-top_down..
        System.out.println("Number of ways sdf: "+util(limit));

        scanner.close();
    }
}