//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>& nums, int k,int num){
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            
            sum += ceil((double)nums[i]/(double)num);
            
        }
        
        if(sum <= k) return true;
        return false;
    }
    
    int getMax(vector<int> &arr){
        int maxi = INT_MIN;
        
      for(int i=0;i<arr.size();i++)
      {
          maxi=max(maxi,arr[i]);
      }
        
        return maxi;
    }
    
    int getMin(vector<int> &arr){
        int mini = INT_MAX;
        
      for(int i=0;i<arr.size();i++)
      {
          mini=min(mini,arr[i]);
      }
        
        return mini;
    }
    
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        // int s = getMin(nums);
        int s = 1;
        int e = getMax(nums);
        
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(isPossible(nums,K,mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends