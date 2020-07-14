class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Storing the sum of all the contigious subarrays
        vector<int> sum;
        for(int i=0;i<n;i++){
            int smallSum=0;
            for(int j=i;j<n;j++){
                smallSum=smallSum+nums[j];
                sum.push_back(smallSum);
            }
        }
        // Sorting the sum array
        sort(sum.begin(),sum.end());
        int ans=0;
        left--;
        right--;
        // Calculating the sum from left to right
        for(int i=left;i<=right;i++){
            ans=ans+sum[i];
        }
        return ans;
    }
};
