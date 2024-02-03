//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        
        int left = 0,right = 0;
        int zeroCnt = 0, ans = INT_MIN;
        
        while(right < n){
            if(arr[right] == 0){
                zeroCnt++;
            }
            
            if(zeroCnt > m){
                if(arr[left] == 0){
                    zeroCnt--;
                }
                left++;
            }
            
            ans = max(ans,right-left+1);
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
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends