class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        if(rows==0)
            return 0;
        int cols=obstacleGrid[0].size();
        long long dp[rows][cols];
        memset(dp,0,sizeof(dp));
        for(int i=rows-1;i>=0;i--){
            if(obstacleGrid[i][cols-1])
                break;
            dp[i][cols-1]=1;
        }
        for(int j=cols-1;j>=0;j--){
            if(obstacleGrid[rows-1][j])
                break;
            dp[rows-1][j]=1;
        }
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-2;j>=0;j--){
                if(obstacleGrid[i][j])
                    continue;
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
