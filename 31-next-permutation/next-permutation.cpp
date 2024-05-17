class Solution {
public:
    void reverse(vector<int>& nums, int i, int j){
        while(i<j){
            swap(nums[i], nums[j]);
            i++; j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find last inversion
        // reverse entire array last inversion onwards
        // swap lastInversion-1 element with firstGreater element
        int lastInversion = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i+1]) {
                lastInversion = i;
            } else {
                break;
            }
        }
        reverse(nums, lastInversion, n-1);
        if(lastInversion!=0){
            int firstGreater = lastInversion;
            while(firstGreater<n && nums[lastInversion-1]>=nums[firstGreater]){
                firstGreater++;
            }
            swap(nums[firstGreater], nums[lastInversion-1]);
        }
            
    }
};

// 2, 5, 4, 3, 1