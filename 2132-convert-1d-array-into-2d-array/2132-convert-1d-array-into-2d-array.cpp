class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         vector<vector<int>> v;
        int need = m * n;
        if(original.size() > need || original.size() < need){
            return v;
        }
        if(original.size() == need) {
            int k = 0;
            for(int i = 1 ; i <= m ; i++) {
                int c = n;
                vector<int> p;
                while(c--){
                    p.push_back(original[k]);
                    k++;
                }
                v.push_back(p);
            }
            return v;
        }
        return v;
    }
};