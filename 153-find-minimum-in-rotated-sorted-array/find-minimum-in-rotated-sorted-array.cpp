class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            int mid = low + (high-low)/2;
            if(nums[mid]<=nums[high]){ // right half sorted
                ans = min(ans, nums[mid]);
                high = mid-1;
            } else { //left half sorted
                ans = min(ans, nums[low]);
                low=mid+1;
            }
        }
        return ans;
    }
};