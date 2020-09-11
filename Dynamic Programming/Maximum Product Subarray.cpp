class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int currentMaximum=nums[0];
        int currentMinimum=nums[0];
        int maximumAns=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(currentMaximum,currentMinimum);
            currentMaximum=max(nums[i],currentMaximum*nums[i]);
            currentMinimum=min(nums[i],currentMinimum*nums[i]);
            maximumAns=max(maximumAns,currentMaximum);
        }
        return maximumAns;
    }
};
