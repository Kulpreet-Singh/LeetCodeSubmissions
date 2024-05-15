class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        for(auto it: nums){
            mpp[it]++;
        }
        vector<int> majorityElements;
        for(auto it: mpp){
            if(it.second>n/3){
                majorityElements.push_back(it.first);
            }
        }
        return majorityElements;
    }
};