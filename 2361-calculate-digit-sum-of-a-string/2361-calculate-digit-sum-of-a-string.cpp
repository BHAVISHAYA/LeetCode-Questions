class Solution {
public:
    string digitSum(string s, int k) {
        vector<int> ans;
        int num=0;

//Till the size of string is greater, while loop will work.
        while(s.size()>k){
            for(int i=0;i<s.size();i++){
                num=0;
                for(int j=0;j<k;j++){
//while increasing j, always check whether i is less than the actual size.
                    if(i<s.size()) 
                    num=num+s[i]+'0'-96;
//If s[i]=1 then to change it in integer add '0' it become 97 thus sub 96.
                    i++;
                }
            i--;
            ans.push_back(num);
        }
        s.clear();   //clear previous string
        for(int i=0;i<ans.size();i++){
            s=s+to_string(ans[i]); 
//change each number to string for concatenation 
        }
    
        ans.clear();
        }
        return s;
    
    }
};