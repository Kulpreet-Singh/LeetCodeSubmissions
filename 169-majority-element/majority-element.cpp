class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        for(auto it: nums){
            mpp[it]++;
            if(mpp[it]>n/2){
                return it;
            }
        }
        return -1;
    }
};