class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        int n = ops.size();

        for(int i=0;i<n;i++){
            if(ops[i] == "+"){
                if(st.size() >= 2){
                    int n1 = st.top();
                    st.pop();
                    int n2 =st.top();
                    st.pop();

                    // to push again previous two and their sum
                    st.push(n2);
                    st.push(n1);
                    st.push(n1+n2);
                }
            }
            else if(ops[i] == "D"){
                int num = st.top();
                st.push(2*num);
            }
            else if(ops[i] == "C"){
                st.pop();
            }
            else{
                st.push(stoi(ops[i]));
            }
        }

        int ans = 0;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};