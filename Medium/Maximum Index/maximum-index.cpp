//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> ltr(n,0);
        vector<int> rtl(n,n-1);
        int mintillnow=a[0];
        for(int i=1;i<n;i++){
            if(a[i]<mintillnow){
                ltr[i] = i;
                mintillnow=a[i];
            }
            else{
                ltr[i]=ltr[i-1];
            }
        }
        int maxtillnow=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>maxtillnow){
                rtl[i]=i;
                maxtillnow=a[i];
            }
            else{
                rtl[i]=rtl[i+1];
            }
        }
        int i=0,j=0;
        int maxdiff=0;
        while(i<n && j<n){
            if(a[ltr[i]]<=a[rtl[j]]){
                maxdiff = max(maxdiff,rtl[j]-ltr[i]);
                j++;
            }
            else{
                i++;
            }
        }
        return maxdiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends