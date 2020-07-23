class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        // Set for storing all the unique values of & 
        set<int> prev;
        // Currently the answer is INT_MAX
        int ans=INT_MAX;
        for(auto x:arr){
            set<int> current;
            // First include the number itself
            current.insert(x);
            for(auto y:prev){
                // for every element in array, we will take & with all the elements in the prev set
                current.insert(y&x);
            }
            for(auto y:current){
                // Calculating the value closest to target
                ans=min(ans,abs(y-target));
            }
            // Now, the current set becomes the prev set for the next element in arr
            prev=current;
        }
        return ans;
    }
};
