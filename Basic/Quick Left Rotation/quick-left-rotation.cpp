//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   if(k >= n){
	       k = k%n;
	   }
	   vector<int> temp(n);
	   
	   
	   for(int i=k;i<n;i++){
	       temp[i-k] = arr[i];
	   }
	   
	   for(int i=0;i<k;i++){
	       temp[n-k+i] = arr[i];
	   }
	   
	   for(int i=0;i<n;i++){
	       arr[i] = temp[i];
	   }
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends