//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<int> ans;
        vector<bool> prime(n+1,true);
        prime[0] = prime[1] = false;
        
        for(int i=2;i<=n;i++){
            if(prime[i]){
                ans.push_back(i);
                for(int j=2*i;j<=n;j=j+i){
                    prime[j] = false;
                }
            }
        }
        

        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends