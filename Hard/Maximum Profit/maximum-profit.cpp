//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int n, int prices[]) {
        // code here
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));
       
        for(int ind=n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=K;cap++){
                        if(buy){
                            dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                        }
                        else{
                             dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                        }                    
                }
            }
        }
        
        return dp[0][1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends