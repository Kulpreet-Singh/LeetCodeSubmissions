class Solution {
public:
    // O(logn) approach using binary search based on odd and even index
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    // move to right half
                    low = mid + 1;
                } else if (nums[mid] == nums[mid - 1]) {
                    // move to left half
                    high = mid - 1;
                } else {
                    return nums[mid];
                }

            } else {
                if (nums[mid] == nums[mid + 1]) {
                    // move to left half
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};