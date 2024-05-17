class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        int p = 0, n = 0;
        int bit = 0;
        while (p < nums.size() && n < nums.size()) {
            if (bit == 0) {
                if (nums[p] > 0) {
                    result.push_back(nums[p++]);
                    bit = 1;
                } else {
                    p++;
                }
            } else {
                if (nums[n] < 0) {
                    result.push_back(nums[n++]);
                    bit = 0;
                } else {
                    n++;
                }
            }
        }
        while (p < nums.size() && bit == 0) {
                if (nums[p] > 0) {
                    result.push_back(nums[p++]);
                    bit = 1;
                } else {
                    p++;
                }
            
        }
        while (n < nums.size() && bit == 1) {
                if (nums[n] < 0) {
                    result.push_back(nums[n++]);
                    bit = 0;
                } else {
                    n++;
                }
            
        }
        return result;
    }
};