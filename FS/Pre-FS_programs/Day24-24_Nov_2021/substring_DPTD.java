import java.util.*;
class Sol{
    static HashMap<String,Boolean> h1=new HashMap<>();
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        String t=sc.next();
        System.out.println(sub(s,t,s.length()-1,t.length()-1));
        
        System.out.println(h1);
        
    }
    static boolean sub(String s1,String s2,int m,int n){
        
        if(m==0) return true;
        if(n==0) return false;
        String k=m+"|"+n;
        System.out.println("At "+k+": "+h1);
        if((!h1.containsKey(k)) &&(s1.charAt(m)==s2.charAt(n))){
            h1.put(k,sub(s1,s2,m-1,n-1));
        }
        else{
            h1.put(k,sub(s1,s2,m,n-1));
        }
        return h1.get(k);
    }
}

// Code by M. Rohan, CSE-A, KMIT