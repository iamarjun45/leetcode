class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int nums_size=nums.size();
        prefixSum=vector<int>(nums_size+1);
        prefixSum[0]=0;
        for(int i=1;i<=nums_size;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return prefixSum[j+1]-prefixSum[i];
    }
};
