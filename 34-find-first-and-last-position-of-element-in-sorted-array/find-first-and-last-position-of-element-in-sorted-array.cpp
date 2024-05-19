class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(), nums.end(), target)){
            return {-1, -1};
        }
        int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        return {lb, max(0, ub-1)};
    }
};