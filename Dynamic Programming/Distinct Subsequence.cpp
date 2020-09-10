class Solution {
public:
    int numDistinct(string s, string t) {
        int s_length=s.size();
        int t_length=t.size();
        long long dp[s_length+1][t_length+1];
        for(int i=0;i<=s_length;i++) dp[i][0]=1;
        for(int i=1;i<=t_length;i++) dp[0][i]=0;
        for(int i=1;i<=s_length;i++){
            for(int j=1;j<=t_length;j++){
                dp[i][j]=(s[i-1]==t[j-1]?(dp[i-1][j]+dp[i-1][j-1]):dp[i-1][j]);
            }
        }
        return dp[s_length][t_length];
    }
};
