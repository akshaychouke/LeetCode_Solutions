//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
        int s = 0,e = n-1;
        
        int ans = INT_MAX;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            ans = min(ans,arr[mid]);
            
            if(arr[mid] >= arr[e]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends