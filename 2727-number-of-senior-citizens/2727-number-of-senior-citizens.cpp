class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ctS = 0;
        for(int i = 0 ; i < details.size() ; i++) {
            string s = "";
            s.push_back(details[i][11]);
            s.push_back(details[i][12]);
            int num = stoi(s);
            if(num > 60)
            ctS++;
        }
        return ctS;
    }
};