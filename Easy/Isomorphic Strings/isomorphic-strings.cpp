//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        unordered_map<char,char> mpp1;
        unordered_map<char,bool> mpp2;
        
        int n = str1.length();
        int m = str2.length();
        
        if(n != m) return false;
        
        int i=0,j=0;
        
        while(i<n && j<m){
            char ch1 = str1[i];
            char ch2 = str2[j];
            
            if(mpp1.find(ch1) != mpp1.end()){
                if(mpp1[ch1] != ch2) return false;
            }
            else{
                if(mpp2[ch2] == true) return false;
                else{
                    mpp1[ch1] = ch2;
                    mpp2[ch2] = true;
                }
            }
            
            i++;
            j++;
        }
        
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends