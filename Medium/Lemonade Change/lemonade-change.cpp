//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        unordered_map<int,int> mpp;
        for(int it : bills){
            if(it == 5){
                mpp[5]++;
            }
            else if(it == 10){
                mpp[10]++;
                if(mpp[5] > 0){
                    mpp[5]--;
                }
                else{
                    return false;
                }
            }
            else{
                if(mpp[10] > 0){
                    mpp[10]--;
                    if(mpp[5] > 0){
                        mpp[5]--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(mpp[5] >= 3){
                        mpp[5] -= 3;
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends