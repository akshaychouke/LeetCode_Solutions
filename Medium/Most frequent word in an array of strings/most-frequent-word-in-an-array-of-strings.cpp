//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n)
    {
        int maxiIndex = INT_MIN;
        int maxi = INT_MIN;
        string ans = "";

        map<string, pair<int, int>> mpp; // Fix: Added a closing angle bracket here.

        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]].first++;
            if (mpp[arr[i]].second == 0)
            {
                mpp[arr[i]].second = i+1;
            }
        }

        for (auto it : mpp)
        {
            if (it.second.first > maxi)
            {
                maxi = it.second.first;
                maxiIndex = it.second.second;
                ans = it.first;
            }
            else if (it.second.first == maxi)
            {
                if (it.second.second > maxiIndex)
                {
                    maxiIndex = it.second.second;
                    maxi = it.second.first;
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends