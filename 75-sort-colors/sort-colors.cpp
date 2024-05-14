class Solution {
public:
//Dutch National flag algorithm
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid =0;
        int high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid]==1){
                mid++;
                // only incrementing mid here since 1 is expected in the middle only
            } else if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
                // not incrementing mid here since low and mid can still be unsorted
            }
        }
    }
};