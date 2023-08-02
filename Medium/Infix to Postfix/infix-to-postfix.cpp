//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int prec(char c) {
      if (c == '^')
        return 3;
      else if (c == '/' || c == '*')
        return 2;
      else if (c == '+' || c == '-')
        return 1;
      else
        return -1;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string ans = "";
        
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            
            //if character is not operator or bracket
            if((ch >= 'a' && ch <= 'z') || (ch>='A' && ch <='Z') || (ch>='0' && ch<='9')){
                ans+=ch;
            }
            
            else if(ch == '('){
                st.push(ch);
            }
            
            //check if the character is ')' it will add the stack elements till ( is found
            else if(ch == ')'){
                while(st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                
                //if the encountered character has hiher or eqaul precedence than top of the stack 
                while(!st.empty() && (prec(s[i]) <= prec(st.top()))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        
        //to add reamaning characters
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends