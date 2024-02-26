//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    void dfs(int ind, string& curr, vector<string>& res, string& s) {
            if(ind == s.size()) {
                if(curr != "") res.push_back(curr);
                return;
            }
            
            curr += s[ind];
            ind += 1;
            dfs(ind, curr, res, s);
            
            curr.pop_back();
            dfs(ind, curr, res, s);
        }
        vector<string> AllPossibleStrings(string s){
            string curr = "";
            vector<string> res;
            
            dfs(0, curr, res, s);
            sort(res.begin(), res.end());
            
            return res;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends