class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;
        int n = nums.size();
        int len=0;
        while(r<n){
            if(nums[r]==0){
                l = r+1;
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};