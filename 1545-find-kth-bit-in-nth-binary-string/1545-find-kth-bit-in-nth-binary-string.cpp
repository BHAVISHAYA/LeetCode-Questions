class Solution {
public:
    char solve(int i, int n, string &str, int k) {
        if(i == n) return str[k - 1];

        str += "1";
        for(int i = str.size() - 2 ; i >= 0 ; i--) {
            if(str[i] == '0') str.push_back('1');
            else str.push_back('0');
        }

        return solve(i + 1, n, str, k);
    }
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        string s = "0";
        return solve(1, n, s, k);
    }
};