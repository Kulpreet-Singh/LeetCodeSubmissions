class Solution {
public:
// O(n) approach using xor
    int singleNonDuplicate(vector<int>& nums) {
        int val = 0;
        for(auto num: nums){
            val = val ^ num;
        }
        return val;
    }
};