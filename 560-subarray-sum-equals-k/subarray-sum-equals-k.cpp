class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int prefixSum = 0;
        int count = 0;
        for (auto num : nums) {
            prefixSum += num;
            if (prefixSum == k) {
                count++;
            }
            if (mpp.find(prefixSum - k) != mpp.end()) {
                count += mpp[prefixSum - k];
            }

            mpp[prefixSum]++;
        }
        return count;
    }
};