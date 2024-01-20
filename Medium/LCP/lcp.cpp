//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    string CompareStrings(string s,string t){
        int i = 0,j=0;
        
        while(i < s.length() && j < t.length()){
            if(s[i] != t[j]){
                break;
            }
            i++;
            j++;
        }
        
        return s.substr(0,i);
    }
    
    string LCP(string arr[], int n)
    {
        // code here
        string longest = arr[0];
        
        for(int i=1;i<n;i++){
            longest = CompareStrings(longest,arr[i]);
        }
        
        if(longest == "") return "-1";
        return longest;
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}
// } Driver Code Ends