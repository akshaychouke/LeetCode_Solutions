//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kthPrime(int n, int k){
        // code here
        vector<bool> prime(n+1,true);
        vector<int> factors;
        
        prime[0] = prime[1] = false;
        
        for(int i=2;i*i<=n;i++){
            if(prime[i]){ 
                for(int j=i*i;j<=n;j=j+i){
                    prime[j] = false;
                }
            }
        }
        
        for(int i=2;i<=n;i++){
            if(prime[i]){
                if(n%i == 0){
                    // factors.push_back(i);
                    while(n%i == 0){
                        factors.push_back(i);
                        n = n/i;
                        if(n == 0) break;
                    }
                }
            }
        }
        
        if(factors.size() < k) return -1;
        
        return factors[k-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        Solution ob;
        cout<<ob.kthPrime(n, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends