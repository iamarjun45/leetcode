class Solution {
    vector<int> a;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        a = nums;
        vector<int> curr;
        dfs(0, n, curr);
        return ans;
    }
    void dfs(int idx, int n, vector<int>& curr) {
        if (idx == n){
            ans.push_back(curr);
            return;
        }
        dfs(idx + 1, n, curr);
        curr.push_back(a[idx]);
        dfs(idx + 1, n, curr);
        curr.pop_back();
    }
};
