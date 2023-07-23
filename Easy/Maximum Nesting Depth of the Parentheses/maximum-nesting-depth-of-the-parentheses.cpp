//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        
        stack<char> st;
        
        int maxi = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')' && !st.empty()){
                st.pop();
            }
            
            int sz = st.size();
            maxi = max(maxi,sz);
        }
        
        return maxi;
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends