class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int suffix=1;
        int prefix=1;
        for(int i=1;i<n;i++){
            prefix=nums[i-1]*prefix;
            result[n-i]*=suffix;
            suffix = suffix*nums[n-i];
            result[i]*=prefix;
        }
        result[0]*=suffix;
        return result;
    }
};