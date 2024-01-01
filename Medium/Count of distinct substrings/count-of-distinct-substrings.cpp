//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
class Node {
public:
  Node *link[26];

  bool containsKey(char ch) { return (link[ch - 'a'] != NULL); }

  void put(char ch, Node *node) { link[ch - 'a'] = node; }

  Node* get(char ch) { return link[ch - 'a']; }
};

int countDistinctSubstring(string s)
{
    //Your code here
      Node* root = new Node();
      int n = s.length();
      int cnt = 0;
    
      for (int i = 0; i < n; i++) {
        Node* node = root;
        for (int j = i; j < n; j++) {
          if (!node->containsKey(s[j])) {
            node->put(s[j], new Node());
            cnt++;
          }
          node = node->get(s[j]);
        }
      }
    
      return cnt + 1;
    }