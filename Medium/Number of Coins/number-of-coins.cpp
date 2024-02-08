//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Solve(vector<int> &coins, int M, int V, vector<int> &dp) {
        if (V == 0) return 0;

        if (dp[V] != -1) return dp[V];
        int res = INT_MAX;

        for (int i = 0; i < M; i++) {
            if (coins[i] <= V) {
                int subproblem = Solve(coins, M, V - coins[i], dp);
                if (subproblem != INT_MAX) { // Check if subproblem is solvable
                    int ans = 1 + subproblem;
                    res = min(res, ans);
                }
            }
        }

        return dp[V] = res;
    }
    int minCoins(vector<int> &coins, int M, int V) {
        // Your code goes here
        vector<int> dp(V + 1, -1);
        int result = Solve(coins, M, V, dp);
        return result == INT_MAX ? -1 : result; // Return -1 if not possible
    }

};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends