class Solution {
public:
    int integerBreak(int n) {
        if(n==0)
            return 0;
        vector<int> dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=0;
            for(int j=i-1;j>=1;j--){
                dp[i]=max(dp[i],max(dp[i-j],i-j)*max(dp[j],j));
            }
        }
        return dp[n];
    }
};
