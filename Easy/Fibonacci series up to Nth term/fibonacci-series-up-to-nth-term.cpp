//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int> ans;
        int mod = 1000000007;
        
        int first = 0,sec = 1;
        ans.push_back(first);
        ans.push_back(sec);
        
        for(int i=1;i<n;i++){
            int temp = (first + sec)%mod;
            ans.push_back(temp);
            first = sec;
            sec = temp;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends