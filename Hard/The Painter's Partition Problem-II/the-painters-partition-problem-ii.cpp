//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:

    bool isPossible(int arr[], int k,long long mid,int n){
        long long cnt = 1,sum = 0;
    
        for(int i=0;i<n;i++){
            if(arr[i] > mid) return false;
    
            if(sum + arr[i] > mid){
                cnt++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
    
        if(cnt > k) return false;
        return true;
    }
    
    long long getMax(int arr[], int n){
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
        }
    
        return maxi;
    }
    
    long long getSum(int arr[], int n){
        long long sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        return sum;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time

        long long s = getMax(arr,n);
        long long e = getSum(arr,n);
    
        long long ans = 0;
    
        while(s <= e){
            long long mid = s + (e-s)/2;
    
            if(isPossible(arr,k,mid,n)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends