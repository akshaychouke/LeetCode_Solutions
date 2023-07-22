//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string str1, string str2){
        
        // Your code here
        map<char,int>mpp1;
        map<char,int>mpp2;
    
    
        for(char ch : str1){
            mpp1[ch]++;
        }
    
        for(char ch : str2){
            mpp1[ch]--;
            if(mpp1[ch] == 0){
                mpp1.erase(ch);
            }
        }
    
    
        for(char ch : str2){
            mpp2[ch]++;
        }
    
        for(char ch : str1){
            mpp2[ch]--;
            if(mpp2[ch] == 0){
                mpp2.erase(ch);
            }
        }
    
    
        if(mpp1.size() == 0 && mpp2.size() ==0 ) return true;
        return  false;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends