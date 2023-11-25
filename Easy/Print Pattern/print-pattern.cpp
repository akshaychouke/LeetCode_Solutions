//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void Solve1(vector<int> &ans,int num,int n){
        if(num <= 0){
            ans.push_back(num);
            Solve2(ans,num+5,n);
            return;
        }
        
        ans.push_back(num);
        Solve1(ans,num-5,n);
    }
    
    void Solve2(vector<int> &ans,int num,int n){
        if(num == n){
            ans.push_back(num);
            return;
        }
        
        ans.push_back(num);
        Solve2(ans,num+5,n);
    }
    vector<int> pattern(int N){
        // code here
        if(N <= 0) return {N};
        vector<int> ans;
        ans.push_back(N);
        Solve1(ans,N-5,N);
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends