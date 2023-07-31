class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        
        vector<bool> prime(n+1,true);   //starting me sabhi ko prime banao
        
        prime[0] = prime[1] = false;       // 0 and 1 are not prime
        
        for(int i=2;i*i<n;i++){       //check from 2 to n-1 
            if(prime[i]){       // if prime then increase count by one                 
                for(int j=i*i;j<n;j=j+i){   // make all numbers not prime whoever comes in i table
                    prime[j] = false;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(prime[i]) count++;
        }
        return count;
        
    }
};