//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

long long Solve(int ind, int buy, vector<long long>& prices, vector<vector<long long>>& dp) {
    int n = prices.size();
    if (ind >= n) return 0;

    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy) {
        return dp[ind][buy] = max(-prices[ind] + Solve(ind + 1, 0, prices, dp), 0 + Solve(ind + 1, 1, prices, dp));
    } else {
        return dp[ind][buy] = max(prices[ind] + Solve(ind + 2, 1, prices, dp), Solve(ind + 1, 0, prices, dp));
    }
}

long long maximumProfit(vector<long long>& prices, int n) {

        vector<vector<long long>> dp(n+2,vector<long long>(2,0));
       
        for(int ind=n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                if(buy == 1){
                     dp[ind][buy] = max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                     dp[ind][buy] = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
}

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends