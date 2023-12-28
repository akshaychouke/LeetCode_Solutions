//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
 bool match(string wild, string pattern)
    {
        if(wild == "*") return true;
        int n = wild.length();
        int m = pattern.length();
        vector<vector<int>> v(n+1,vector<int>(m+1,0));
        v[n][m] = 1;
        
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(wild[i] == pattern[j] and v[i+1][j+1] == 1) v[i][j]=1;
                if(wild[i] == '?' and v[i+1][j+1] == 1) v[i][j] = 1;
                if(wild[i] == '*' and (v[i+1][j+1] == 1 || v[i+1][j] == 1)){
                    while(j>=0){
                        v[i][j] = 1;
                        j--;
                    }
                }
    
            }
        }
        
        return v[0][0];
    }


};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends