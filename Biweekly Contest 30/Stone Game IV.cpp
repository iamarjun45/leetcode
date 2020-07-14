class Solution {
public:
    bool winnerSquareGame(int n) {
        // Creating a dp array
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            // Can move 1, 4, 9, 16, i steps at a time
            for(int j=1;j*j<=i;j++){
                // Transition
                dp[i]|=!dp[i-j*j];
            }
        }
        return dp[n];
    }
};
