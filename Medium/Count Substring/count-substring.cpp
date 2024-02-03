//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        
        int left = 0,right = 0,end = s.length()-1;
        unordered_map<char,int> mpp;
        int ans = 0;
        while(right < s.length()){
            mpp[s[right]]++;
            while(mpp['a'] && mpp['b'] && mpp['c']){
                ans += 1 + (end-right);
                mpp[s[left]]--;
                left++;
            }
            right++;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends