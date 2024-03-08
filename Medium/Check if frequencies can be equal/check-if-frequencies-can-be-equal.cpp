//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
bool sameFreq(string s)
{
    // code here 
    
    map<int,int>mp;
    
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    
    int cnt=mp[s[0]];
    bool flag=0;
    
    for(auto i:mp){
        if(i.second!=cnt){
            flag=1;
        }
    }
    
    if(flag==0){
        return true;
    }
    
    for(char ch='a';ch<='z';ch++){
        if(mp.find(ch)==mp.end())continue;
        mp[ch]--;
        if(mp[ch]==0){
            mp.erase(ch);
           
        }
       int cnt=0;
         flag=0;
        int check=-1;
        for(auto i:mp){
            if(check==-1){
                cnt=i.second;
                check=8;
            }
            if(i.second!=cnt){
                flag=1;
            }
        }
        mp[ch]++;
        if(flag==0)return true;
    }
    
    return false;
}
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends