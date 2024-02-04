//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 int solve(vector<int>& arr ,int n,int k){
        
        int i = 0, j = 0,res=0;
        unordered_map<int, int> mp;
        while (j<n) {
            mp[arr[j]]++;
            while (mp.size()>k) {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
        
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return solve(arr,N,k) - solve(arr,N,k-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends