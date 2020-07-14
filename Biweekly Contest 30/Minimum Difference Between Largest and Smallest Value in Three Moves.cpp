class Solution {
public:
    int minDifference(vector<int>& nums) {
        // Base Case: Array size is small. All the elements can be made equal.
        if(nums.size()<=4)
            return 0;
        // Sorting the array
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        // There are total 4 choices. 
        // Either make first three smallest elements equal to largest element,then difference=nums[n-1]-nums[3]
        // Either make first two smallest elements  and the largest element equal to third smallest element,then difference=nums[n-2]-nums[2]
        // Either make first two largest elements and the smallest element equal to third largest element,then difference=nums[n-3]-nums[1]
        // Either make first three largest elements equal to smallest element,then difference=nums[n-4]-nums[0]
        for(int i=3,j=nums.size()-1;i>=0;i--,j--){
            ans=min(ans,nums[j]-nums[i]);
        }
        return ans;
    }
};
