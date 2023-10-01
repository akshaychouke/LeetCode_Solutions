class Solution {
public:
string rev(string st){
    int n = st.length();
    int i=0,j=n-1;

    while(i<=j){
        swap(st[i],st[j]);
        i++;
        j--;
    }
    return st;
}
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        string temp = "";
        for(int i=0;i<n;i++){
            if(s[i] != ' '){
                temp+=s[i];
            }
            else {
                // reverse(temp.begin(),temp.end());
                temp = rev(temp);
                ans+=temp;
                if(i<n-1){
                    ans+=" ";
                }
                temp = "";
            }
    }
     temp = rev(temp);
        ans+=temp;
    return ans;
    }
};