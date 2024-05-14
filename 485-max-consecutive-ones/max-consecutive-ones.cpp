class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int r=0;
        int n = nums.size();
        int len=0;
        int cnt = 0;
        while(r<n){
            if(nums[r]==0){
                cnt = 0;
            } else {
                cnt++;
            }
            len = max(len, cnt);
            r++;
        }
        return len;
    }
};