//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include<bits/stdc++.h>
class Solution {
public:
    bool isPali(int num){
     string str = to_string(num);
     string rev = str;
     reverse(str.begin(),str.end());
     return rev == str;
    }
    
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0;i<n;i++){
    	    if(!isPali(a[i])) return 0;
    	}
    	
    	return 1;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends