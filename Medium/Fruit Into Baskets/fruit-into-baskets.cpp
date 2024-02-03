//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int totalFruits(int n, vector<int> &fruits) 
    {
        int start=0,end=0;
        unordered_map<int,int>mp;
        int ans=0;
        while(end<n)
        {
            mp[fruits[end]]++;
            if(mp.size()>2)
            {
                ans=max(ans,end-start);
                while(mp.size()>2)
                {
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]==0)
                        mp.erase(fruits[start]);
                    start++ ;
                }
            }
            end++ ;
        }
        ans=max(ans,end-start);
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends