//{ Driver Code Starts
//Initial Template for Java
//problem Name (3 OCT): Column name from a given column number

import java.io.*;
import java.util.*;
import java.lang.*; 
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
    		System.out.println (new Solution().colName (n));
        }
        
    }
}



// } Driver Code Ends


//User function Template for Java

class Solution
{
    String colName (long n)
    {
        // your code here
        String ans = ""; long value = 0;

        

        while(n > 0){

         

         if(n% 26 == 0){ value = 26; n = (n/26)-1; }

         

         else{ value = n % 26; n /=26;}

            

         ans = ((char)(value+64))+ans;

        

        }

        

        return ans;
    }
}