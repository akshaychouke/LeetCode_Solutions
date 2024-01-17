//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int m,int k,int day,vector<int> &arr){
        
        int cnt = 0,sum = 0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                sum += (cnt)/k;
                cnt = 0;
            }
        }
        
        sum += cnt/k;
        
        if(sum >= m) return true;
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
    
    
    int solve(int M, int K, vector<int> &arr){
      // Code here
      int s = getMin(arr);
      int e = getMax(arr);
      int ans = -1;
      
      if(M*K > arr.size()) return -1;
      
      while(s <= e){
          int mid = s + (e-s)/2;
          
          if(isPossible(M,K,mid,arr)){
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
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends