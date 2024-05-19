class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurence = -1;
        int lastOccurence = -1;
        int high = nums.size() - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                firstOccurence = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        high = nums.size() - 1;
        low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                lastOccurence = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {firstOccurence,lastOccurence};
    }
};