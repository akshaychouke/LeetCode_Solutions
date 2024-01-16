//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long firstOcc(vector<long long>& arr, long long n, long long k){
        long long s=0;
        long long e=n-1;
        long long ans=-1;
        while(s<=e){
            long long mid = s+(e-s)/2;
            
            if(arr[mid] == k){
                ans = mid;
                e=mid-1;
            }
            else if(arr[mid]>k){
                e=mid-1;
            }
            else if(arr[mid]<k){
                s=mid+1;
            }
        }
        return ans;
    }
    
    long long LastOcc(vector<long long>& arr, long long n, long long k){
        long long s=0;
        long long e=n-1;
        long long ans=-1;
        while(s<=e){
            long long mid = s+(e-s)/2;
            
            if(arr[mid] == k){
                ans = mid;
                s=mid+1;
            }
            else if(arr[mid]>k){
                e=mid-1;
            }
            else if(arr[mid]<k){
                s=mid+1;
            }
        }
        return ans;
    }
    
    pair<long,long> indexes(vector<long long> v, long long k)
    {
        // code here
        int n = v.size();
        
        pair<long long,long long>p;
        p.first=firstOcc(v,n,k);
        p.second=LastOcc(v,n,k);
        
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends