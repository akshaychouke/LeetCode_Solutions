//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code 
        
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(auto it : nums){
            mpp[it]++;
        }
        
        for(auto it : mpp){
            int n1 = it.first;
            int n2 = it.second;
            
            if(n2 > n/3){
                ans.push_back(n1);
            }
        }
        
        if(ans.size() == 0) ans.push_back(-1);
        sort(ans.begin(),ans.end());
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends