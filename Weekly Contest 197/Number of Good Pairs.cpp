class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Size
        int size=nums.size();
        // Total Elements
        int count=0;
        // Comparing ith element with (i+1) to size elements
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                // If equal, increase count by 2
                if(nums[i]==nums[j])
                    count++;
            }
        }
        return count;
    }
};
