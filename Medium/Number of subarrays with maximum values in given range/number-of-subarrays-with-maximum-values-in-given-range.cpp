//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long long int i = 0, j = 0, sum = 0, ans = 0;
        
        while(j < n){
            if(a[j] >= L && a[j] <= R){
                sum = j - i + 1;
            }
            else if(a[j] > R){
                sum = 0;
                i = j + 1;
            }
            
            ans += sum;
            j++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends