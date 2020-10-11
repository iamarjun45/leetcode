class Solution {
public:
    vector<vector<int>> twoSum(vector<int>&nums,int target,int start){
        vector<vector<int>>ans;
        int low=start,high=nums.size()-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum<target||(low>start&&nums[low]==nums[low-1]))
                low++;
            else if(sum>target||(high<nums.size()-1&&nums[high]==nums[high+1]))
                high--;
            else{
                ans.push_back({nums[low],nums[high]});
            low++;
            high--;
                }
        }
        return ans;
    }
    vector<vector<int>> kSum(vector<int>&nums,int target,int start, int k){
        vector<vector<int>>ans;
        if(start==nums.size()||nums[start]*k>target||target>nums[nums.size()-1]*k)
            return ans;
        if(k==2)
            return twoSum(nums,target, start);
        for(int i=start;i<nums.size();i++){
            if(i==start||nums[i]!=nums[i-1]){
                for(auto v:kSum(nums,target-nums[i],i+1,k-1)){
                    v.push_back(nums[i]);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,target,0,4);
    }
};
