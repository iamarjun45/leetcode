class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
        int rows=matrix.size();
        int cols=(rows==0?0:matrix[0].size());
        int dp[cols+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=rows;i++){
            int prev=0;
            for(int j=1;j<=cols;j++){
                int temp=dp[j];
                dp[j]=(matrix[i-1][j-1]=='1'?1+min(dp[j-1],min(temp,prev)):0);
                ans=max(ans,dp[j]);
                prev=temp;
            }
        }
        return ans*ans;
    }
};
