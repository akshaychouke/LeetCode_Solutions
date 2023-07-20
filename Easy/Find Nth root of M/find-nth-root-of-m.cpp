//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
  int low = 1,high = m/2;
  int root = 0;
  int ans = 0;
  
  if(m == 1) return m;
  if(n == 1) return m;
  while(low <= high){
    int mid = low + (high-low)/2;
    double temp = pow(mid,n);
    if(temp == m){
      ans = mid;
      root = temp;
      break;
    }
    else if(temp > m){
      high = mid - 1;
    }
    else{
      low = mid+1;
    }
  }

  if(root != m) return -1;
  return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends