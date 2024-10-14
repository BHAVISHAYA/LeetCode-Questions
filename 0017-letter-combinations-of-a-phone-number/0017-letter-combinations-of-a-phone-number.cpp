class Solution {
public:
    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    void help(int i, string &s, string &temp, vector<string> &ans) {
        if(i >= s.size()) {
            ans.push_back(temp);
            return;
        }

        string str = m[s[i]];
        for(int j = 0 ; j < str.size() ; j++) {
            temp.push_back(str[j]);
            help(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> ans;
        if(digits.size() == 0) return ans;
        help(0, digits, temp, ans);
        return ans;
    }
};