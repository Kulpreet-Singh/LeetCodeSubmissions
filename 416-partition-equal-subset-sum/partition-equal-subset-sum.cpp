class Solution {
public:
    bool helper(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        if (k == 0) {
            return true;
        }
        if (i < 0) {
            return false;
        }
        if (dp[i][k] != -1)
            return dp[i][k];
        bool take = false;
        if (nums[i] <= k) {
            take = helper(i - 1, k - nums[i], nums, dp);
        }
        bool notTake = helper(i - 1, k, nums, dp);
        return dp[i][k] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int k = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return helper(n - 1, k, nums, dp);
    }
};