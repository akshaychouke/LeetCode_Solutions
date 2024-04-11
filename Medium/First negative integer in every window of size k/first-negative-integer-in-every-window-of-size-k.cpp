//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> ans;
    
    long long mini = 0;
    long long i = 0, j = 0;
    
    while(j<N){
        if(mini == 0 && A[j] < 0){
            mini = A[j];
        }
        
        if(j - i + 1 == K){
            ans.push_back(mini);
            
            if(mini == A[i]){
                mini = 0;
                j = i;
            }
            i++;
        }
        j++;
    }
    
    return ans;
 }