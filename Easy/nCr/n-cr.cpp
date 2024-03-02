//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
long int ncr(int n, int r){
    // Complete the function here
    int mod = 1e9 + 7;
    long int ans = 1;
    for(int i = 0; i < r; i++) {
        ans = ((ans % mod) * (n - i) % mod) % mod;
        ans = (ans * modInverse(i + 1, mod)) % mod; // Using modular inverse to divide by (i + 1)
    }
    return ans;
}
long int modInverse(long int a, long int m) {
    long int m0 = m;
    long int y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        long int q = a / m;
        long int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends