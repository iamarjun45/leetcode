class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_length=s1.size();
        int s2_length=s2.size();
        int s3_length=s3.size();
        if(s3_length!=s1_length+s2_length)
            return false;
        bool dp[s1_length+1][s2_length+1];
        dp[0][0]=true;
        for(int i=1;i<=s1_length;i++)
            dp[i][0]=(s1[i-1]==s3[i-1]?dp[i-1][0]:false);
        for(int i=1;i<=s2_length;i++)
            dp[0][i]=(s2[i-1]==s3[i-1]?dp[0][i-1]:false);
        for(int i=1;i<=s1_length;i++)
            for(int j=1;j<=s2_length;j++){
                dp[i][j]=false;
                dp[i][j]|=(s2[j-1]==s3[i+j-1]?dp[i][j-1]:false);
                dp[i][j]|=(s1[i-1]==s3[i+j-1]?dp[i-1][j]:false);
            }
        return dp[s1_length][s2_length];
    }
};
