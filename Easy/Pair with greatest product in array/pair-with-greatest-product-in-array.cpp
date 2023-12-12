//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
        
int findGreatest(int arr[], int n)
{
    int ans = -1;
    unordered_map <int,int> ump;
    for(int i=0; i<n; i++)
        ump[arr[i]]++;
    for(int i=0; i<n; i++){
        if(ump[1]>0 && ump[arr[i]]>1){
            ans = max(ans, arr[i]);
            continue;
        }
        for(int j=2; j*j<=arr[i]; j++){
        if(ump[j]>0 && arr[i]%j == 0 && ump[arr[i]/j]>0){
            if(j == arr[i]/j && ump[j]<2)
                 continue;
            ans = max(ans, arr[i]);
            break;
        }
        }
    }
    return ans;
    
}
};

//{ Driver Code Starts.

// Drivers code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.findGreatest(a,n)<<endl;
    }
}

// } Driver Code Ends