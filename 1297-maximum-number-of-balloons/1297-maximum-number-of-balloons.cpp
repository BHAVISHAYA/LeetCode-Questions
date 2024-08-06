class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26,0);
        for(int i=0;i<text.size();i++){
            v[text[i]-'a']++;
        }
        int mini=v[1];//for b
        mini=min(v[0],mini);//for a
        mini=min(v[11]/2,mini);//for l
        mini=min(mini,v[14]/2);// for o
        mini=min(mini,v[13]);
        return mini;
    }
};