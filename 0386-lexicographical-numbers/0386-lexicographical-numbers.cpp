class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        for(int i = 1 ; i <= n ; i++) {
            string s = "";
            s += to_string(i);
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end());
        vector<int> v;
        for(int i = 0 ; i < ans.size() ; i++) {
            int a = stoi(ans[i]);
            v.push_back(a);
        }
        return v;
    }
};