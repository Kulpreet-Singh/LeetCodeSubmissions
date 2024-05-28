class Solution {
public:
    // O(n) approach using xor
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0) {
                if (mid!=n-1 && nums[mid] == nums[mid + 1]) {
                    // move to right half
                    low = mid + 1;
                } else {
                    if (mid!=0 && nums[mid] == nums[mid - 1]) {
                        // move to left half
                        high = mid - 1;
                    } else {
                        return nums[mid];
                    }
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