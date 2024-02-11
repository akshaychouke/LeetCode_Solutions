//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(),intervals.end());
         
         int start = intervals[0][0],end = intervals[0][1];
         
         vector<vector<int>> ans;
         
         for(int i = 0;i< intervals.size();i++){
            int st = intervals[i][0];
            int en = intervals[i][1];
            
            if(st <= end){
                end = max(end,en);
            }else{
                ans.push_back({start,end});
                start = st;
                end = en;
            }
         }
         
        ans.push_back({start,end});
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends