//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
    int FirstOcc(int arr[], int n, int x) {
      int ans = -1;
      int s = 0, e = n - 1;
    
      while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
          ans = mid;
          e = mid - 1;
        } else if (arr[mid] > x) {
          e = mid - 1;
        } else {
          s = mid + 1;
        }
      }
    
      return ans;
    }
    
    int LastOcc(int arr[], int n, int x) {
      int ans = -1;
      int s = 0, e = n - 1;
    
      while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
          ans = mid;
          s = mid + 1;
        } else if (arr[mid] > x) {
          e = mid - 1;
        } else {
          s = mid + 1;
        }
      }
    
      return ans;
    }
	int count(int arr[], int n, int x) {
	    // code here
	 
	   int ls = FirstOcc(arr,n,x);
	   int rs = LastOcc(arr,n,x);
	   
	   if(ls == -1|| rs == -1) return 0;
	   int ans = rs - ls;
	    return ans + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends