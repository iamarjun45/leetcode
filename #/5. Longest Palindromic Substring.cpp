class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)
            return "";
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int maximum = 1, begin = 0;
        // Single length substrings
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        //  Length two substring
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                maximum = 2;
                begin = i;
            }
        }
        // Substrings of length i+1
        for(int i = 2; i < n; i++){
            for(int j = 0; j<n-i; j++){
                int start = j;
                int end = j+i;
                if(s[start] == s[end] && dp[start+1][end-1]){
                    dp[start][end] = dp[start+1][end-1];
                    if(end - start + 1 > maximum){
                        maximum = end - start + 1;
                        begin = start;
                    }
                }
            }
        }
        return s.substr(begin, maximum);
    }
};
