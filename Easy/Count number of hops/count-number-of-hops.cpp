//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod = 1000000007;
    long long Solve(int n,vector<int> &dp){
        if(n<0) return 0;
        if(n == 0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] =(Solve(n-1,dp) + Solve(n-2,dp) + Solve(n-3,dp))%mod;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<int> dp(n+1,-1);
        return Solve(n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends