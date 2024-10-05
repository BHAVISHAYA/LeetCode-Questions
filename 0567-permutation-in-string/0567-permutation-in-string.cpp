class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        // Using sliding window technique

        int slow = 0, fast = 0, k = s1.size();
        unordered_map<char, int> m;
        for(auto &value : s1) {
            m[value]++;
        }
        int count = m.size();

        while(fast < s2.size()) {
            // Step 1 -> Calculation part
            if(m.find(s2[fast]) != m.end()) {
                m[s2[fast]]--;
                if(m[s2[fast]] == 0) 
                count--;
            }

            // When we don't hit the window
            if(fast - slow + 1 < k) {
                fast++;
            }

            // When we hit the window
            else if(fast - slow + 1 == k) {
                if(count == 0) return true;


                // Just do the reverse of step 1
                if(m.find(s2[slow]) != m.end()) {
                    m[s2[slow]]++;
                    if(m[s2[slow]] == 1)
                    count++;
                }

                slow++;
                fast++;
            }
        }
        return false;
    }
};