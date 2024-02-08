//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
    int Solve(int n,vector<int> &dp){
        if(n<=0) return 0;

        if(dp[n] != -1) return dp[n];

        int mini = INT_MAX;

        for(int i=1;i*i<=n;i++){
            int sq = i*i;

            int ans = 1 + Solve(n-sq,dp);
            mini = min(mini,ans);
        }

        return dp[n] = mini;
    }
    
	int MinSquares(int n)
	{
        vector<int> dp(n+1,-1);

        return Solve(n,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends