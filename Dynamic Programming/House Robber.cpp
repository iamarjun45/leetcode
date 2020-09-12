class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_length=nums.size();
        if(nums_length==0)
            return 0;
        int dp[nums_length+1];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=nums_length;i++)
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        return dp[nums_length];
    }
};
