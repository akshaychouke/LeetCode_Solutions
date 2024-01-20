//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        int n = s.length();
        
        string ans = "";
        int i = 0,j=0;
        
        while(i < n){
            
            while(s[i] != '.' && i < n){
                i++;
            }
            
            string word = s.substr(j,i-j);
            reverse(word.begin(),word.end());
            j = i + 1;
            ans += word;
            if(i <= n-1){
                ans +='.';
            }
            i++;
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
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends