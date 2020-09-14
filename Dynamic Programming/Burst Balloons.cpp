class Solution {
public:
    int maxCoins_(vector<int> &nums, int si, int ei, vector<vector<int>> &dp){
    if (dp[si][ei]!=0)
        return dp[si][ei];
    int lVal=(si==0) ? 1 : nums[si - 1];
    int rVal=(ei==nums.size()-1) ? 1 : nums[ei + 1];
    int ans=0;
    for(int cut=si;cut<=ei;cut++){
        int leftTreeCost= cut == si ? 0 : maxCoins_(nums, si,cut - 1, dp);
        int rightTreeCost= cut == ei ? 0 : maxCoins_(nums, cut + 1, ei, dp);
        int cost = leftTreeCost + lVal * nums[cut] * rVal + rightTreeCost;
        if (cost > ans){
            ans = cost;
        }
    }
    return dp[si][ei] = ans;
}

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        return maxCoins_(nums,0,n-1,dp);
    }
};
