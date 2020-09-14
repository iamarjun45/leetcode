class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_length=nums.size();
        int dp[nums_length+1];
        dp[0]=0;
        int maximum=0;
        for(int i=1;i<=nums_length;i++){
            dp[i]=1;
            for(int j=i-1;j>0;j--){
                if(nums[i-1]>nums[j-1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            maximum=max(maximum,dp[i]);
        }
        return maximum;
    }
};
