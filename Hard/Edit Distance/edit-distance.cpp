//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solver(string s, string t,int i,int j,vector<vector<int>> &dp){

        if (i == -1) {
           return j + 1;
        }

        if (j == -1) {
           return i + 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
           return dp[i][j] = solver(s,t,i-1,j-1,dp);
        }
        
        else{
            
            int l = 0;
            int r = 0;
            int p = 0;
            
            l = 1 + solver(s,t,i,j-1,dp);
            r = 1 + solver(s,t,i-1,j,dp);
            p = 1 + solver(s,t,i-1,j-1,dp);
            
            return dp[i][j] = min({l,r,p});
            
        }
        
    }
    
    int editDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solver(s,t,n-1,m-1,dp);
        // Code here
    }

};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends