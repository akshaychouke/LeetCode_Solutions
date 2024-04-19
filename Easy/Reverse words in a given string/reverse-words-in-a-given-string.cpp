//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans = "";
        int n = S.length();
        int i = n-1;
        
        while(i>=0){
            int j = i;
            while(i>=0 and S[i] != '.'){
                i--;
            }
            
            string st = S.substr(i+1,j-i);
            ans += st;
            if(i > 0){
                ans += '.';
            }
            i--;
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends