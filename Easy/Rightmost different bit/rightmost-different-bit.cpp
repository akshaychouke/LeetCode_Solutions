//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        if(m == n) return -1;
        
        int ans = 0;
        
        while(m > 0 or n > 0){
            ans++;
            // int mLastBit = (m & 1);
            // int nLastBit = (n & 1);
            
            if((m & 1) != (n & 1)) return ans;
            
            n = n>>1;
            m = m>>1;
        }
        
        return ans+1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends