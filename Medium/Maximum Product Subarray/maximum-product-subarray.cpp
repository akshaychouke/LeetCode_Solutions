//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxi = INT_MIN;

	    long long pref = 1 , suff = 1;
	    
	    for(auto it : arr){
	        pref *= it;
	        maxi = max(maxi,pref);
	        if(pref == 0){
	            pref = 1;
	        }
	    }
	    
	    for(int i = n-1; i>=0;i--){
	        suff *= arr[i];
	        maxi  = max(maxi,suff);
	        
	        if(suff == 0){
	            suff = 1;
	        }
	    }
	    
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends