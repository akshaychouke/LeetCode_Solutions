//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> arr)
  {
      // code here
       vector<int> wt(N,0);
       
       for(int i=0;i<N;i++){
           if(arr[i] != -1){
               wt[arr[i]] += i;
           }
       }
       
       int maxi = INT_MIN;
       
       for(int i=0;i<N;i++){
           maxi = max(maxi,wt[i]);
       }
       
       for(int i = N-1;i>=0;i--){
           if(maxi == wt[i]) return i;
       }
       
       return 0;
       
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends