class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;

        string ans = "";

        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(st.empty()) st.push(s[i]);   
            else{
                if((st.top() == '(' && s[i] == '(') || (st.top() == ')' && s[i] == ')')) {
                    ans += s[i];
                    st.pop();
                } 
                else {
                    ans += st.top();
                    st.push(s[i]);
                }
            }
        }

        return ans;
    }
};