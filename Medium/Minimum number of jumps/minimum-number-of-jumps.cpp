//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
int minJumps(int arr[], int n){
        // Your code here
            if (n == 0 || n == 1){ return 0; }
            if (arr[0] == 0) {return -1; }
           

            int maxReach = arr[0];
            int steps = arr[0];
            int jumps = 0;
            for (int i = 1; i < n - 1; i++)
            {
                steps--;
                if (maxReach < arr[i] + i)
                {
                    maxReach = arr[i] + i;
                }
        
                if (steps == 0)
                {
                    jumps++;
                    steps = maxReach - i;
                    if (steps == 0) { return -1;  }
                }
            }
            return jumps + 1;
    }


};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends