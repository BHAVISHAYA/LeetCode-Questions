class Solution {
public:
    unordered_map<char, int> m = {{'(', 1}, {')', -1}};
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ct = 0;
        for(auto &bracket : s) {
            if(st.empty()) {
                if(m[bracket] == 1) {
                    st.push(bracket);
                }
            }
            else {
                if(m[st.top()] + m[bracket] == 0) {
                    st.pop();
                    ct += 2;
                }
                else 
                st.push(bracket);
            }
        }
        return (s.size() - ct);
    }
};