class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        unordered_set<char> st;
        int ans = 0;

        for(int right = 0;right<n;right++){
            //check if character is already counted or not
            if(st.count(s[right]) == 0){
                st.insert(s[right]);
                ans = max(ans,right-left+1);
            }
            else{   //if character is counted
                while(st.count(s[right])){    //keep removing elements until the repeated element is deleted
                    st.erase(s[left++]);
                }
                st.insert(s[right]);
            }
        }

        return ans;
    }
};
