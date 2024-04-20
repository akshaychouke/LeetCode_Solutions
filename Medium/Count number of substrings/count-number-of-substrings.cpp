//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string s,int k){
        int n = s.length();
        long long int ans = 0;
        int cnt = 0,i =0,j=0;
        
        vector<int> vec(26,0);
        
        while(j<n){
            vec[s[j]-'a']++;
            if(vec[s[j]-'a'] == 1) cnt++;
            
            while(cnt > k){
                vec[s[i]-'a']--;
                if(vec[s[i]-'a'] == 0) cnt--;
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        
        return ans;
    }
    
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	return solve(s,k) - solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends