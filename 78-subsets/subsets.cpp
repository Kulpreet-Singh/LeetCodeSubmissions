class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int subsets = 0; subsets < (1 << n); subsets++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (subsets & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};