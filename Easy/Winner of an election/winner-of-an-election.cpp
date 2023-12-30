//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n){
        map<string,int>m;
        for(int i=0; i<n; i++)m[arr[i]]++;
        
        int cnt=0;
        string s;
        for(auto it:m){
            if(it.second>cnt){
                s=it.first;
                cnt=it.second;
            }
            else if(it.second==cnt and it.first<s){
                s=it.first;
            }
        }
        
        vector<string>res;
        string ss=to_string(cnt);
        res.push_back(s);
        res.push_back(ss);
        
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends