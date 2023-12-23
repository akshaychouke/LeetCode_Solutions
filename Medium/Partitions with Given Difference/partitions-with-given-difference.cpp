//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = (int)(1e9+7);
    int find(int ind,int sum,vector<int>&arr,vector<vector<int>> &dp){
        if(ind == 0){
            if(sum==0 && arr[0]==0) return 2;
            if(sum == 0 || arr[0]==sum) return 1;
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int take = 0;
        if(arr[ind]<=sum) take = find(ind -1 ,sum - arr[ind],arr,dp);
        int not_take = find(ind-1,sum,arr,dp);
        
        return dp[ind][sum] =(take+not_take)%mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int total_sum = 0;
        for(auto it : arr) total_sum += it;
        if(total_sum-d < 0 || (total_sum-d)%2) return 0;
        int s2 = (total_sum-d)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return find(n-1,s2,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends