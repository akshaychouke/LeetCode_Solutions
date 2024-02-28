//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        
        int first = (s[s.size()-1]) - '0';
        
        if(s.size() == 1){
            if(s[0] != '8')
                return false;
            return true;
        }
        
        int sec = (s[s.size()-2]) - '0';
        
        if(s.size() == 2){
            first = (s[s.size()-1]) - '0';
            sec = (s[s.size()-2]) - '0';
            
            sec = sec * 10 + first;
            
            return (sec % 8 == 0 ? 1 : -1);
        }
        
        int third = (s[s.size()-3]) - '0';
        
        
        third = third * 10 + sec;
        third = third * 10 + first;
        
        
        return ((third % 8  == 0) ? 1 : -1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends