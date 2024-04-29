//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(int i, int j, string &s, string t, vector<vector<int>> &dp) {
      if (i < 0 || j < 0)
        return 0;
    
      if (dp[i][j] != -1)
        return dp[i][j];
    
      if (s[i] == t[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, s, t, dp);
    
      return dp[i][j] = max(lcs(i - 1, j, s, t, dp), lcs(i, j - 1, s, t, dp));
    }

    int countMin(string str){
    //complete the function here

      int n = str.length();
      string t = str;
      reverse(t.begin(), t.end());
      vector<vector<int>> dp(n, vector<int>(n, -1));
      int paliLen =
          lcs(n - 1, n - 1, str, t, dp); // length of longest palindromic subsquence
      return n - paliLen;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends