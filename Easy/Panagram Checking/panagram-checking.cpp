//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
 
    bool checkPangram (string &a) {
      for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
      vector<int>v(26,0);
      for(int i=0;i<a.length();i++){
          if(a[i]>='a' && a[i]<='z'){
              v[a[i]-'a']++;
          }
      }
      for(int i=0;i<26;i++){
          if(!v[i]) return false;
      }
      return true;
    
    }

};


//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends