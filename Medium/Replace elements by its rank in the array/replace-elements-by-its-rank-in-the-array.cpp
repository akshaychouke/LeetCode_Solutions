//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){

          vector<int> ans(n, 0);
          priority_queue<int, vector<int>, greater<int>> pq;
          unordered_map<int, int> mpp;
          for (auto it : arr) {
            pq.push(it);
          }
        
          int rank = 1;
          while (!pq.empty()) {
            if (mpp[pq.top()] == 0) {
              mpp[pq.top()] = rank;
              rank++;
            }
            pq.pop();
          }
        
          for (int i = 0; i < n; i++) {
            ans[i] = mpp[arr[i]];
          }
        
          return ans;

    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends