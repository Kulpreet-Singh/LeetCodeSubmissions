class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurence = -1;
        int lastOccurence = -1;
        int high = nums.size() - 1;
        int low = 0;
        int prevMid = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                firstOccurence = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
                if(firstOccurence == -1){
                    prevMid = mid;
                }
            }
        }
        if(firstOccurence==-1){
            return {-1, -1};
        }
        if(prevMid==-1)
            high = nums.size() - 1;
        else
            high = prevMid;
        low = firstOccurence;
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