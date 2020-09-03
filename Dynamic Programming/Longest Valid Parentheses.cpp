class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n==0||n==1)
            return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        int ans=0;
        if(s[0]=='('&&s[1]==')'){
            dp[1]=2;
            ans=2;
        }
        else
            dp[1]=0;
        for(int i=2;i<n;i++){
            if(s[i-1]=='('&&s[i]==')')
                dp[i]=2+dp[i-2];
            else if(s[i-1]==')'&&s[i]==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                dp[i]=2+dp[i-1];
                if(i-dp[i-1]-2>=0)
                    dp[i]+=dp[i-dp[i-1]-2];
            }
            else
                dp[i]=0;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
