class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        for(int i=1;i<n;i++){
            prefix[i]=nums[i-1]*prefix[i-1];
            suffix[n-i-1] = suffix[n-i]*nums[n-i];
        }
        for(int i=0;i<n;i++){
            prefix[i] = prefix[i]*suffix[i];
        }
        return prefix;
    }
};