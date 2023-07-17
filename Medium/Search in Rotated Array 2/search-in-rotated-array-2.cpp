//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& arr, int key) {
        // Code here
        
        int l=0,h=N-1;
         while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==key) return 1;
            if(arr[mid]==arr[l]&&arr[mid]==arr[h]){
                l++; h--; continue;
            }
            if(arr[mid]>=arr[l]){   // left sorted
                if(arr[mid]>=key && arr[l]<=key) h=mid-1;
                else l=mid+1;
            }
            else{ //right sorted
                if(arr[mid]<=key && arr[h]>=key) l=mid+1;
                else h=mid-1;
            }
        }
        return 0;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends