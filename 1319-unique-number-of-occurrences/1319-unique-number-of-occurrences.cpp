class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v;
        unordered_map<int, int> m;
        for(int i = 0 ; i < arr.size() ; i++){
            m[arr[i]]++;
        }
        for(auto &value : m){
            v.push_back(value.second);
        }
        unordered_map<int, int> m1;
        for(int i = 0 ; i < v.size() ; i++){
            m1[v[i]]++;
        }
        for(auto &value : m1){
            if(value.second != 1)
            return false;
        }
        return true;
    }
};