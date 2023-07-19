//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int isPossible(vector<int> v, int num, int n) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += ceil((double)v[i] / (double)num);
  }

  return total;
 }
    int Solve(int N, vector<int>& arr, int H) {
        // Code here
        int maxi = INT_MIN;
        
        for(int i=0;i<N;i++){
            maxi = max(maxi,arr[i]);
        }
        
        
        int low = 0,high = maxi;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            int totalH = isPossible(arr,mid,N);
            
            if(totalH <= H){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return low;
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends