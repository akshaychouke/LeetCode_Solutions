//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int Solve(int idx,int sum,int coins[],vector<vector<long long int>> &dp){
        
        if(idx < 0){
            if(sum == 0) return 1;
            return 0;
        }
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        //stay here
        long long int select = 0;
        if(coins[idx] <= sum){
            select = Solve(idx,sum-coins[idx],coins,dp);
        }
        
        
        //change index
        long long int notSelect = Solve(idx-1,sum,coins,dp);
        
        
        return dp[idx][sum] = select+notSelect;
        
    }
    
    long long int count(int coins[], int N, int sum) {
        sort(coins,coins+N);
        
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
        return Solve(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends