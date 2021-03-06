class Solution {
public:
    bool isMatch(string s, string p) {
        int stringLength=s.length();
        int patternLength=p.length();
        bool dp[stringLength+1][patternLength+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<=patternLength;i++){
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<=stringLength;i++){
            for(int j=1;j<=patternLength;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]|=dp[i-1][j-1];
                if(p[j-1]=='*'){
                    dp[i][j]|=dp[i-1][j];
                    dp[i][j]|=dp[i][j-1];
                }
            }
        }
        return dp[stringLength][patternLength];
    }
};
