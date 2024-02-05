//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int Solve(string str, int k){
      int n = str.length();
      int left = 0, right = 0;
      int ans = -1;
      unordered_map<char, int> mpp;
    
      while (right < n) {
        mpp[str[right]]++;
        
        if(mpp.size() == k){
            ans = max(ans, right - left + 1);
        }else if(mpp.size() > k){
            while (mpp.size() > k) {
              mpp[str[left]]--;
              if (mpp[str[left]] == 0) {
                mpp.erase(str[left]);
              }
              left++;
            }
        }
        right++;
      }
    
      return ans;
    }
    
    int longestKSubstr(string s, int k) {
    // your code here
        return Solve(s,k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends