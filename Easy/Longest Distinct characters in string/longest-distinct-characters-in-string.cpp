//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int maxi = INT_MIN;
    int n = S.length();
    
    for(int i=0;i<n;i++){
        int j = i;
        
        unordered_map<char,int> mpp;
        
        for(;j<n;j++){
            if(mpp[S[j]] >= 1){
                break;
            }
            mpp[S[j]]++;
        }
        
        maxi = max(maxi,j-i);
    }
    
    return maxi;
}