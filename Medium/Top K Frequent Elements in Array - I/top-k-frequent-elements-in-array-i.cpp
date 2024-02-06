//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mpp;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(int it : nums){
            mpp[it]++;
        }
        
        for(auto it : mpp){
            pq.push(make_pair(it.second,it.first));
        }
        
        for(int i=1;i<=k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends