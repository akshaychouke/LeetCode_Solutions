//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        
        if(n%2 != 0) return false;
        
        vector<bool> used(n,false);
        for(int i=0;i<n-1;i++){
            bool isFound = false;
            if(used[i] == true) continue;
            
            for(int j=i+1;j<n;j++){
                if(used[j] == true) continue;
                
                if((nums[i]+nums[j])%k == 0){
                    used[i] = true;
                    used[j] = true;
                    isFound = true;
                    break;
                }
            }
            if(isFound == false) return isFound;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends