class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        int currAns=nums[0];
        int maximum=nums[0];
        for(int i=1;i<size;i++){
            currAns=max(currAns+nums[i],nums[i]);
            maximum=max(maximum,currAns);
        }
        return maximum;
    }
};
