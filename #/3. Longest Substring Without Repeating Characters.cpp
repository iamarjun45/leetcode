class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ans = 0;
        int last = 0;
        for(int i = 0; i < s.length(); i++){
            if(m.count(s[i]) > 0){
                last = max(last, m[s[i]]);
            }
            ans = max(ans, i - last + 1);
            m[s[i]] = i + 1;
        }
        return ans;
    }
};

