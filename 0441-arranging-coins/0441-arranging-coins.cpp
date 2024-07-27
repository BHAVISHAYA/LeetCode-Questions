class Solution {
public:
    int arrangeCoins(int n) {
        int ct = 0, i = 1;
        while(n >= i) {
            ct++;
            n -= i;
            i++;
        }
        return ct;
    }
};