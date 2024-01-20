//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        int n = s.length();
        
        string ans = "";
        int i = n-1,j=n-1;
        
        while(i >= 0){
            
            while(s[i] != '.' && i >= 0){
                i--;
            }
            
            string word = s.substr(i+1,j-i);
            // reverse(word.begin(),word.end());
            ans += word;
            j = i - 1;
            if(i > 0){
                ans +='.';
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