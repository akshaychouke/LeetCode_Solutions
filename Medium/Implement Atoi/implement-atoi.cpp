//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = str.length();
        if(n == 1) return str[0] - '0';
        
        int ans = 0;
        bool flag = false;
        
        if(str[0] == '-'){
            flag = true;
        }
        
        for(int i=0;i<n;i++){
            char ch = str[i];
            int num = ch - '0';
            if(flag && i == 0) continue;
            
            if(num < 0 || num > 9) return -1;
            ans += num;
            if(i != n-1){
                ans = ans*10;
            }
        }
        if(flag){
            ans = ans*-1;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends