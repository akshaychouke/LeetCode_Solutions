//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
#include <bits/stdc++.h>
    int longestSubsequence(string s1, string s2) {
      int n = s1.length();
      int m = s2.length();
    
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
      for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
      }
    
      for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
      }
    
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
    
      return dp[n][m];
    }
    int longestPalindromeSubsequence(string s) {
      // Write your code here.
      string t = s;
      reverse(t.begin(), t.end());
    
      return longestSubsequence(s, t);
    }
    int findMinInsertions(string S){
        // code here 
        int n = S.length();
        
        return n - longestPalindromeSubsequence(S);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends