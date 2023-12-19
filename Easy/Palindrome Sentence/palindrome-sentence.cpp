//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // code here 
	    string ans = "";
	    for(int i=0;i<s.length();i++){
	        char ch = s[i];
	        if(isalnum(ch)){
	            ans.push_back(ch);
	        }
	    }
	    
	    string temp = ans;
	    reverse(ans.begin(),ans.end());
	    
	    return ans == temp;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends