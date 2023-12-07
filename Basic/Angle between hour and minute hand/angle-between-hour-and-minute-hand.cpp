//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getAngle(int hour , int minutes) {
        // code here
        double angle = abs(hour*30.0  - (5.5)*minutes);
        return min(angle,360 - angle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}
// } Driver Code Ends