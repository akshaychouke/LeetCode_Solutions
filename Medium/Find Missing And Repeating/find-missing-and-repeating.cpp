//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int> mpp;
        
        int f1 = 0,f2 = 0;
        for(auto it:arr){
            mpp[it]++;
        }
        
        for(int i=1;i<=n;i++){
            if(mpp[i] == 0){
                f1 = i;
            }
            else if(mpp[i] == 2){
                f2 = i;
            }
        }
        
        return {f2,f1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends