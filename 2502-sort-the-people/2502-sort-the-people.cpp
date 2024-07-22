class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> v(names.size());
        vector<pair<int, string>> p;
        for(int i = 0 ; i < names.size() ; i++)
        {
            p.push_back(make_pair(heights[i], names[i]));
        }
        sort(p.rbegin(), p.rend());
        for(int i = 0 ; i < p.size() ; i++)
        {
            v[i] = p[i].second;
        }
        return v;
    }
};